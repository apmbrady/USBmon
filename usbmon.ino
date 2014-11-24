#include <SoftwareSerial.h>

SoftwareSerial XBee(0,1);

boolean currState = 0;
boolean oldState = 0;
int i = 0;

void setup() {

  XBee.begin(9600);
  XBee.println("Hello World");
  delay(1000);
}

void loop() {

  currState = UDINT & B00000001;

  if (oldState == currState) {
    i = 0;
  } else {
    i++;

  }

  if (i == 10) {
    if (oldState == 0) {
      // Alarm
      XBee.println("Power off");
    } else {
      // Not Alarm
      XBee.println("Power on");
    }

    oldState = currState;
  }

  delay(1000);
}
