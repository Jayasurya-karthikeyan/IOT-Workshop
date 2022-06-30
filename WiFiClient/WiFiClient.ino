/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <WiFi.h>
#include<FirebaseESP32.h>
//#include<BluetoothSerial.h>

//BluetoothSerial SerialBT;

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//#define WIFI_SSID "COE CHROMIUM"
//#define WIFI_PASSWORD "Welcom@123"
#define FIREBASE_HOST "esproject32-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "iqadLJMWMKlJATEJ01c6ULmWZJPrsLm94lIspzW1"


#define DHTPIN 2
#define DHTTYPE    DHT11   


DHT_Unified dht(DHTPIN, DHTTYPE);

FirebaseData fbdo;

const char* ssid     = "COE CHROMIUM";
const char* password = "Welcome@123";


void setup()
{
  dht.begin();
//  SerialBT.begin("Enarxi12345");

  pinMode(2,OUTPUT);
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int value = 0;
int i=0;

void loop()
{

  sensors_event_t event;
  dht.temperature().getEvent(&event);

  float temp = event.temperature;

    dht.humidity().getEvent(&event);


      float hum = event.relative_humidity;
    

//for(i;i<100;i++){
//Firebase.setInt(fbdo, "/bruh!",i);
//Firebase.setInt(fbdo, "/br8",i+4);
//} 
//Firebase.setString(fbdo,"/name","..!!");

if(Firebase.getString(fbdo, "/LED")){
//  int b=Firebase.getInt(fbdo, "/LED");
  String a= fbdo.stringData();
  Serial.println(a);

  if(a=="1"){
    digitalWrite(2,HIGH);
  }
  else{
  digitalWrite(2,LOW);
  }

  Firebase.setFloat(fbdo,"/Temperature",temp);
  delay(100);
  Firebase.setFloat(fbdo,"/Humidity",hum);
  delay(100);

}




//delay(3000);
}
