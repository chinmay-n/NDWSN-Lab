#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

int analog_ip = A0;   // select the input pin Photo Diode.
int inputVal = 0;     // to store photo diode input
int tempPin = 3;
float temp;

void setup() {
  Serial.begin(9600);   // Setup Serial Communication.               
  //Serial.print("ROBO INDIA\nroboindia.com\nTutorial on Analog IR Sensor.\n");  
  if (!driver.init())
         Serial.println("init failed");
      
}

void loop(){
    inputVal = analogRead(analog_ip); // Reading and storing analog input value.

        Serial.print("Input Value:");
        Serial.print(inputVal);       // Printing Analog input value of Photo Diode.
        Serial.print("\n");           // moving to new line

        const char msg[10];
      dtostrf(inputVal,6,2,msg);
    Serial.println(msg);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();

    
temp = analogRead(tempPin);

temp = temp * 0.44828125;

Serial.print("TEMPRATURE = ");
Serial.print(temp);
Serial.print("*C");

if(temp>30){
  digitalWrite(8,HIGH);
  if(temp>35){
    char ms[]="TEMPERATURE WARNING";
    Serial.println(ms);
    driver.send((uint8_t *)ms, strlen(ms));
    driver.waitPacketSent();
    }
  }
  else{
    digitalWrite(8,LOW);
    }


Serial.println();

        delay(2000);                   // Waiting for a while.

  
  
}
