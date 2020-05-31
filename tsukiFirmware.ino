#include <Wire.h>
#include <Servo.h>

int valRead;
Servo servo;

int pos = 0;    // variable to store the servo position
int incomingByte = 0;   // for incoming serial data

bool shouldOpenDoor = false;
bool shouldCloseDoor = false;

void setup() {
  Wire.begin(0x8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  servo.attach(9);
  servo.write(90);
}

void receiveEvent(int howMany) {
 while(Wire.available()) {
  char c = Wire.read();
  valRead = c << 1;
  if (valRead == 0) {
    shouldCloseDoor = true;
  } else {
    shouldOpenDoor = true;
  }
 }
}

void openDoor() {
  Serial.println("OPENING DOOR");
  servo.write(0);
  delay(2300);
  servo.write(90);
  Serial.println("DOOR IS OPEN");
}

void closeDoor() {
  Serial.println("CLOSING DOOR");
  servo.write(180);
  delay(2300);
  servo.write(90);
  Serial.println("DOOR IS CLOSED");
}

// the loop function runs over and over again forever
void loop() {
  delay(100);

  if(shouldOpenDoor) {
    shouldOpenDoor = false;
    openDoor();
  }

  if(shouldCloseDoor) {
    shouldCloseDoor = false;
    closeDoor();
  }

}
