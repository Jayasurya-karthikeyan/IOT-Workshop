

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
 int ldr = analogRead(2);
 Serial.println("LDR : " +String(ldr));
 delay(1000);
}
