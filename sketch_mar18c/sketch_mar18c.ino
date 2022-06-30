void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  delay(3000);

  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  delay(3000);

}
