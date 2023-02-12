#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
float hum=29;
float temp=30;
int soil=A0;
int value1;

char ssid[] = "Gpcet-B3";   // your network SSID (name)
char pass[] = "gpcet123";

WiFiClient client;

unsigned long myChannelNumber = 1694153;
const char * myWriteAPIKey = "JBJTPW5BW5C2FWSC";
const char * myReadAPIKey = "EJTTT1S8LKVB6WIW";
void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_STA);
  Serial.begin(9600);
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
   if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
   
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);    
    }
    Serial.println("\nConnected.");
  }
  value1=analogRead(soil);
  Serial.println("soil moisture: ");
  Serial.println(value1);

  ThingSpeak.setField(1, hum);
  ThingSpeak.setField(2, temp);
  ThingSpeak.setField(3, value1);
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(20000);

  float a = ThingSpeak.readFloatField(myChannelNumber, 3, myReadAPIKey); 
  Serial.println("ReadValue from ThingSpeak: ");
  Serial.print(a);
  delay(20000);
 }
