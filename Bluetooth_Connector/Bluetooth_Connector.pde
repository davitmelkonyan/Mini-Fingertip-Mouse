import processing.serial.*;
String ledStatus = "LED: ON";

int lf = 10; // Linefeed in ASCII
Serial myPort; // Create object from Serial class




void setup() {
  size(450,500); //setting the window size
  printArray(Serial.list());
  myPort = new Serial(this, "/dev/cu.RNBT-6B8A-RNI-SPP", 115200); //starts the serial communication, COM5 decided when connecting the laptop to bluetooth
  myPort.bufferUntil(lf); //define up to what char will be read, we have \n every time adruino sends the string ledStatus
  


  ledStatus = myPort.readStringUntil(lf);
  if (ledStatus != null) {
      print(ledStatus);
      }
      
}

void serialEvent (Serial myPort){ //checks if there's available data in Serial Port to be read
  ledStatus = myPort.readStringUntil(lf);
}

/*void loop() {
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
}*/

void draw(){ //also loops
  background(240,240,240);
  fill(20,160,133);
  stroke(33);
  strokeWeight(1);
  rect(50,100,150,50,10); //the On Button
  rect(250,100,150,50,10); //the Off Button
  fill(255);

  textSize(32);
  text("On",60,135);
  text("Off",255,135);
  textSize(24);
  fill(33);
  text("Status:", 180, 200);
  textSize(30);
  textSize(16);
  text(ledStatus,155,240);
  
  

  if(mousePressed && mouseX>50 && mouseX<200 && mouseY>100 && mouseY<150){
    myPort.write('1');
    stroke(255,0,0);
    strokeWeight(2);
    noFill();
    rect(50,100,150,50,10);
    
    print(ledStatus,155,240);
    
  }
  if(mousePressed && mouseX>250 && mouseX<400 && mouseY>100 && mouseY<150){
    myPort.write('0');
    stroke(255,0,0);
    strokeWeight(2);
    noFill();
    rect(250,100,150,50,10);
    
    print(ledStatus,155,240);
  }
}
