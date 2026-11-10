#include <SPI.h>
#include <RF24.h>
RF24 radio(7,8);
const uint8_t VEHICLE_ID=1; // 1..10, same on both ends
uint8_t address[6]={'P','I','N','0','1',0};
void initRadio(){
 address[3]='0'+VEHICLE_ID/10;address[4]='0'+VEHICLE_ID%10;
 Serial.begin(115200);
 if(!radio.begin()){Serial.println(F("RF init failed"));while(true){}}
 radio.setChannel(20+5*VEHICLE_ID);radio.setDataRate(RF24_250KBPS);
 radio.setPALevel(RF24_PA_LOW);radio.setCRCLength(RF24_CRC_16);
 radio.setAutoAck(true);radio.setRetries(3,5);radio.setPayloadSize(sizeof(uint16_t));
}
void setup(){initRadio();radio.openReadingPipe(1,address);radio.startListening();}
void loop(){uint16_t n;while(radio.available()){radio.read(&n,sizeof(n));Serial.println(n);}}
