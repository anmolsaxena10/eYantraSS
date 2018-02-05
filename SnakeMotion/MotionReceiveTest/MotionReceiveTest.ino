#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
	Wire.begin(8);
	Wire.onReceive(receiveEvent);
	Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}


void receiveEvent(int howMany){
	int motion = Wire.read();
	Serial.println(motion);
}
