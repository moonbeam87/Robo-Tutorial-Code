/*
  The circuit:
  RX is digital pin 10 (connect to TX of Xbee)
  TX is digital pin 11 (connect to RX of Xbee)
*/
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial xbee(10, 11); // RX, TX
Servo Lservo; //create left servo object
Servo Rservo; //create right servo object
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  xbee.begin(9600);
  Lservo.attach(5); //servo is connected to digital output 9
  Rservo.attach(6);
  pinMode(13, OUTPUT);
}
void loop() { // run over and over
  while (xbee.available() > 0) {
    char c = xbee.read();
    if (c == 1) {
      move(20, 140, 10);
    }
    if (c == 2) {
      move(140, 20, 10);
    }
    if (c == 3){
      move(90, 20, 10);  
    }
    if (c == 4){
      move(20, 90, 10);  
    }
  }
  //delay(10);
}
void move(int left, int right, int del)
{
  Lservo.write(left);//0 – 180 for older Vex motors. 15 – 165 for new type.
  Rservo.write(right);
  delay(del);
}
