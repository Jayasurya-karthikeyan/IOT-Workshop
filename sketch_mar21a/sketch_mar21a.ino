#include<BluetoothSerial.h>

BluetoothSerial SerialBT;
void setup() {

  // put your setup code here, to run once:
Serial.begin(115200);
SerialBT.begin("Vendhu thanindhadhu Kaadu, *** connectionku accept ah podu!");

}

void loop() {
  // put your main code here, to run repeatedly:
if(SerialBT.available()){
  String data = SerialBT.readString();
  Serial.println("data : "+data);
}
}
