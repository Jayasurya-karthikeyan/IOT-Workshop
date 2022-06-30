#define in 4

void setup() {
  // put your setup code here, to run once:
  pinMode(in,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int a =digitalRead(in);
  Serial.println(a);
  delay(4000);

}
