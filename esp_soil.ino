#include<ESP8266WiFi.h>

int soil=A0;
int value1;


int state;
void setup(){
 pinMode(soil,INPUT);

  
 Serial.begin(9600);
}
void loop(){
 value1=analogRead(soil);
 Serial.println("soil moisture: ");
 Serial.println(value1);
 delay(1000);



   
  
 
}
