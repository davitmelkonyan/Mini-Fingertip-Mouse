#include <Mouse.h>

int horizontalPin = A1;
int verticalPin = A0;
int selectPin = 9;

int verticalZero,horizontalZero;
int verticalValue,horizontalVelue;
const int sensitivity = 200;
int mouseClickFlag = 0;

void setup() {
  Serial.begin(9600);

  pinMode(horizontalPin, INPUT);
  pinMode(verticalPin, INPUT);
  pinMode(selectPin, INPUT);

  digitalWrite(selPin, HIGH);
  delay(1000);

  horizontalZero = analogRead(horizontalPin);
  verticalZero = analogRead(verticalPin);
}

void loop() {
  verticalValue = analogRead(verticalPin) - verticalZero;
  horizontalVelue = analogRead(horizontalPin) - horizontalZero;

  if(verticalValue != 0)
    Mouse.move(0, verticalValue/sensitivity, 0); //Mouse.move(xPos,yPos,Wheel)
  if(horizontalVelue != 0)
    Mouse.move(horizontalVelue/sensitivity,0, 0); //might need to * by -1

  if((digitalRead(selectPin) == 0) && (!mouseClickFlag)){
    mouseClickFlag = 1;
    Mouse.press(MOUSE_LEFT);
  }
  else if(digitalRead(selectPin) && mouseClickFlag){
    mouseClickFlag = 1;
    Mouse.release(MOUSE_LEFT);
  }
}
