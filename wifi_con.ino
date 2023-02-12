#include<ESP8266WiFi.h>
char ssid[] = "Gpcet-B3";
char pass[] = "gpcet123";

WiFiClient client;

void setup(){
   WiFi.mode(WIFI_STA);
   Serial.begin(9600);
  }
void loop(){
  if (WiFi.status()!=WL_CONNECTED){
     Serial.print("ATTEMPTING TO CONNECT");
    }
  while(WiFi.status() != WL_CONNECTED){
     WiFi.begin(ssid,pass);
     Serial.print(".");
     delay(5000);
     
    }
   Serial.println("\nCONNECTED");
  }
  
