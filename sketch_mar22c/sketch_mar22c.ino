#define LDR_PIN 2
# define SAMPLING_TIME 20


bool led_state=false;
bool previous_state=true;
bool current_state= true;
char buff[64];

bool get_ldr(){
  int ldr = analogRead(LDR_PIN);
  //Serial.println(ldr);
  bool val = ldr > 400 ? true: false;
  return val;  
}

char get_byte(){
  char data_byte=0;
  delay(SAMPLING_TIME*1.5);
  for(int i=0;i<8;i++){
    data_byte=data_byte | (char)get_ldr()<<i;
    delay(SAMPLING_TIME);
  }
  return data_byte;
}


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  current_state= get_ldr();
  if(!current_state && previous_state){
    sprintf(buff,"%c", get_byte());
    Serial.print(buff);
  }
  previous_state=current_state;
  
  // put your main code here, to run repeatedly:

}
