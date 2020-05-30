
#include <SoftwareSerial.h>
#include <Servo.h>
int c;

SoftwareSerial xbee(10, 11); // RX, TX
void setup() {
// Open serial communications and wait for port to open:
Serial.begin(9600);
xbee.begin(9600);
}
void loop() { // run over and over
  c = analogRead(A3);
  if(c == 1023 || c == 0){
  xbee.write(c);
  }
}
