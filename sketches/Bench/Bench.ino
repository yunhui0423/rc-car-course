// Lesson 2: USB-tethered, raised wheels only. Joystick fitted to car board.
// Hold SW (D12 to GND) to enable; release immediately to stop.
const uint8_t STBY=4,PWMA=5,PWMB=6,AIN1=2,AIN2=3,BIN1=9,BIN2=10;
const int LEFT_SIGN=1,RIGHT_SIGN=1;
int cx=512,cy=512;
void motor(uint8_t p,uint8_t a,uint8_t b,int v){
 analogWrite(p,0);digitalWrite(a,v>0);digitalWrite(b,v<0);analogWrite(p,abs(v));
}
int axis(int value,int center){
 int d=value-center;
 if(abs(d)<=60)return 0;
 return d>0?constrain(map(d,60,1023-center,0,100),0,100):constrain(map(d,-60,-center,0,-100),-100,0);
}
void setup(){
 const uint8_t pins[]={STBY,PWMA,PWMB,AIN1,AIN2,BIN1,BIN2};
 for(uint8_t i=0;i<7;i++)pinMode(pins[i],OUTPUT);
 digitalWrite(STBY,LOW);pinMode(12,INPUT_PULLUP);Serial.begin(115200);
 long x=0,y=0;for(int i=0;i<100;i++){x+=analogRead(A0);y+=analogRead(A1);delay(5);}
 cx=x/100;cy=y/100;
 if(cx<300||cx>720||cy<300||cy>720){Serial.println(F("Center failed"));while(true){}}
}
void loop(){
 int t=-axis(analogRead(A1),cy),r=axis(analogRead(A0),cx);
 bool enable=digitalRead(12)==LOW;
 int l=enable?constrain(t+r,-100,100):0;
 int rr=enable?constrain(t-r,-100,100):0;
 motor(PWMA,AIN1,AIN2,l*LEFT_SIGN);motor(PWMB,BIN1,BIN2,rr*RIGHT_SIGN);
 digitalWrite(STBY,enable && (l!=0 || rr!=0));
 Serial.print(l);Serial.print(',');Serial.println(rr);delay(20);
}
