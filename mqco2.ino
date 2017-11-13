#include "MQ135.h"
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

char node[]="GAS:";
char conca[80];
 MQ135 gasSensor= MQ135(0);
float rzero=1690.44;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode( 0, INPUT);
  pinMode( 8, OUTPUT);
   if (!driver.init())
         Serial.println("init failed");
//float rzero = gasSensor.getRZero();
}

void loop() {
//  rzero = gasSensor.getRZero();
//  Serial.println(rzero);
float ppm = gasSensor.getPPM();
ppm=ppm*100;
int tmp=int(ppm);
Serial.println(ppm);

 sprintf(conca,"%s %i",node,tmp);
     Serial.println(conca);
    driver.send((uint8_t *)conca, 10);

if(ppm>20){
  digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
    }

     
    
  delay(2000);
}
