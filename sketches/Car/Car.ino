#include <SPI.h>
#include <RF24.h>
// Change VEHICLE_ID identically on both boards: 1..10.
const uint8_t VEHICLE_ID = 1;
RF24 radio(7, 8);
uint8_t address[6] = {'C','A','R','0','1',0};
struct __attribute__((packed)) Command {
  uint16_t seq;
  int16_t throttle;
  int16_t turn;
  uint8_t enable;
};
struct __attribute__((packed)) Status {
  uint16_t seq;
  int16_t left;
  int16_t right;
  uint8_t stopped;
};
static_assert(sizeof(Command)==7, "packet size");
static_assert(sizeof(Status)==7, "packet size");
bool setupRadio() {
  address[3] = '0' + VEHICLE_ID / 10;
  address[4] = '0' + VEHICLE_ID % 10;
  if (!radio.begin()) return false;
  radio.setChannel(20 + VEHICLE_ID * 5); // vehicles 1..10: 2425..2470 MHz
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.setCRCLength(RF24_CRC_16);
  radio.setAutoAck(true);
  radio.setRetries(3, 5);
  radio.enableDynamicPayloads();
  radio.enableAckPayload();
  return true;
}

// Keep false for lesson 1; change to true only after raised-wheel inspection.
const bool MOTOR_ENABLED = false;
const int LEFT_SIGN=1, RIGHT_SIGN=1; // change one sign if a wheel is reversed
const uint8_t STBY=4, PWMA=5, PWMB=6;
const uint8_t AIN1=2, AIN2=3, BIN1=9, BIN2=10;
uint32_t lastRx=0;
bool needNeutral=true;
Status state={0,0,0,1};
void motor(uint8_t p,uint8_t a,uint8_t b,int v){
  analogWrite(p,0);
  digitalWrite(a,v>0);digitalWrite(b,v<0);
  analogWrite(p,abs(v));
}
void stopCar(){
  analogWrite(PWMA,0);analogWrite(PWMB,0);digitalWrite(STBY,LOW);
  state.left=state.right=0;state.stopped=1;
}
void drive(int left,int right){
  motor(PWMA,AIN1,AIN2,left*LEFT_SIGN);
  motor(PWMB,BIN1,BIN2,right*RIGHT_SIGN);
  digitalWrite(STBY,HIGH);
  state.left=left;state.right=right;state.stopped=0;
}
void setup(){
  Serial.begin(115200);
  const uint8_t pins[]={STBY,PWMA,PWMB,AIN1,AIN2,BIN1,BIN2};
  for(uint8_t i=0;i<7;i++) pinMode(pins[i],OUTPUT);
  stopCar();
  if(!setupRadio()){Serial.println(F("RF init failed"));while(true){}}
  radio.openReadingPipe(1,address);
  radio.writeAckPayload(1,&state,sizeof(state));
  radio.startListening();
}
void loop(){
  if(millis()-lastRx>500){needNeutral=true;stopCar();}
  uint8_t pipe;
  while(radio.available(&pipe)){
    uint8_t n=radio.getDynamicPayloadSize();
    if(n!=sizeof(Command)){radio.flush_rx();continue;}
    Command c;radio.read(&c,sizeof(c));
    if(c.throttle < -120 || c.throttle > 120 || c.turn < -120 || c.turn > 120 || c.enable>1) continue;
    lastRx=millis();state.seq=c.seq;
    bool neutral=(c.throttle==0 && c.turn==0);
    if(neutral && !c.enable) needNeutral=false;
    int left=constrain(c.throttle+c.turn,-120,120);
    int right=constrain(c.throttle-c.turn,-120,120);
    if((state.left*left<0) || (state.right*right<0)) needNeutral=true;
    if(!MOTOR_ENABLED || needNeutral || !c.enable || neutral) stopCar();
    else drive(left,right);
    // ACK for the packet just received was already sent by the radio.
    // Prepare status for the NEXT command's ACK; do not label it real-time speed.
    radio.flush_tx();
    radio.writeAckPayload(pipe,&state,sizeof(state));
    Serial.print(state.seq);Serial.print(',');Serial.print(state.left);
    Serial.print(',');Serial.println(state.right);
  }
}
