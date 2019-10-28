//#include <SoftwareSerial.h>

#define ledPin 7
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);//led off
  Serial.begin(9600); //default communication rate
}

void loop() {
  if(Serial.available()>0){
    state = Serial.read();//reads the data
  }

  if(state == '0'){
    digitalWrite(ledPin, LOW);
    Serial.println("LED is off");
    state = 0;
  }else if(state == '1'){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED is on");
    state = 0;
  }
}
