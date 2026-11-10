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

uint16_t seq=0;
int centerX=512, centerY=512;
int axis(int raw, int center) {
  int d=raw-center;
  if (abs(d)<=60) return 0;
  if (d>0) return constrain(map(d,60,1023-center,0,120),0,120);
  return constrain(map(d,-60,-center,0,-120),-120,0);
}
void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT_PULLUP); // hold joystick switch to move
  long sx=0,sy=0;
  for(int i=0;i<100;i++){sx+=analogRead(A0);sy+=analogRead(A1);delay(5);}
  centerX=sx/100;centerY=sy/100;
  if(centerX<300 || centerX>720 || centerY<300 || centerY>720){
    Serial.println(F("Center calibration failed: restart with joystick centered"));
    while(true){}
  }
  if(!setupRadio()){Serial.println(F("RF init failed"));while(true){}}
  radio.openWritingPipe(address);
  radio.stopListening();
}
void loop() {
  static uint32_t sent=0;
  if(millis()-sent<50) return;
  sent=millis();
  Command c={seq++, (int16_t)-axis(analogRead(A1),centerY),
                    (int16_t)axis(analogRead(A0),centerX),
                    (uint8_t)(digitalRead(2)==LOW)};
  bool ok=radio.write(&c,sizeof(c));
  Serial.print(F("ACK="));Serial.print(ok);
  while(radio.available()) {
    uint8_t n=radio.getDynamicPayloadSize();
    if(n!=sizeof(Status)){radio.flush_rx();break;}
    Status s;radio.read(&s,sizeof(s));
    Serial.print(F(" previousSeq="));Serial.print(s.seq);
    Serial.print(F(" L="));Serial.print(s.left);
    Serial.print(F(" R="));Serial.print(s.right);
    Serial.print(F(" stopped="));Serial.print(s.stopped);
  }
  Serial.println();
}
