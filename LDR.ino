#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

int sensorValue;
char node[]="LDR:";
char conca[80];
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);      // sets the serial port to 9600

  pinMode( 0, INPUT);
  pinMode( 8, OUTPUT);
   if (!driver.init())
         Serial.println("init failed");
      
}

void loop() {
  // put your main code here, to run repeatedly:
 sensorValue = analogRead(0);       // read analog input pin 0

  //digitalValue = digitalRead(7); 
if(sensorValue<800){
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
    }
  Serial.println(sensorValue, DEC);  // prints the value read

  //Serial.println(digitalValue, DEC);
//const char msg[10];
  //  dtostrf(sensorValue,6,2,msg);
   
    sprintf(conca,"%s %i",node,sensorValue);
     Serial.println(conca);
    driver.send((uint8_t *)conca, 10);
    driver.waitPacketSent();
  delay(2000);
}
