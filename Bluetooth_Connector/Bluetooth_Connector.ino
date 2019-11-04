
#define ledPin 9
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);//led ON
  Serial.begin(115200); //default communication rate
  Serial.write("LED: ON");
}

void loop() {
  if(Serial.available()>0){
    state = Serial.read();//reads the data
  }

  if(state == '0'){
    digitalWrite(9, LOW);
    Serial.write("LED: OFF");
    state = 0;
  }else if(state == '1'){
    digitalWrite(9, HIGH);
    Serial.write("LED: ON");
    state = 0;
  }
}
