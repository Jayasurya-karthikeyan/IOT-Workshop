String logic 

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
SerialBT.begin("enarxi);
}

void loop() {
  // put your main code here, to run repeatedly:
if(SerialBT.available()){
  data = SerialBT.readStringUntil("/n);
  split(data);
}
}
