/****************Header files**************/
#include <Wire.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>

/*******************************************/

/*************Declarations********************/
RF24 radio(7, 8);
const byte address[6] = "00001";

int motion = -1; //motion initially at standby position
byte sendMotion = 0;

int buzzerPin = 9;
int s0=2, s1=3, s2=4, s3=5, colorSensorOut=6;
bool colorSensor;

/********************************************/

void setup() {
	Serial.begin(9600);
  // put your setup code here, to run once:
	pinMode(A0, OUTPUT);
	pinMode(A1, OUTPUT);
	pinMode(A2, OUTPUT);
	pinMode(buzzerPin, OUTPUT);
	pinMode(s0, OUTPUT);
	pinMode(s1, OUTPUT);
	pinMode(s2, OUTPUT);
	pinMode(s3, OUTPUT);
	pinMode(colorSensorOut, INPUT);
	digitalWrite(s0, HIGH);
	digitalWrite(s1, HIGH);

	//radio.begin();
	//radio.openReadingPipe(0, address);
	//radio.setPALevel(RF24_PA_MIN);

	Wire.begin();

	colorSensor = true;
}

void loop() {
  // put your main code here, to run repeatedly:
	//buzz(5, 50, 500);
	if(colorSensor){
		Serial.println();
		getColor();
	}
	//motion = getData(motion);
	//commandSlaveTo(motion);

	delay(50);
}

/**Function to get data from radio module****/
int getData(int motion){
	radio.startListening();//starting the radio listener
	if(radio.available()){//checking the availability of radio
		radio.read(&motion, sizeof(motion));//reading the input from radio module
	}
  return motion;
}

/********************************************/


bool buzz(int buzzCount, int buzzLength, int buzzDelay){
	int i;
	for(i=0 ; i<buzzCount ; i++){
		analogWrite(buzzerPin, 250);
		delay(buzzLength);
		analogWrite(buzzerPin, 0);
		delay(buzzDelay);
	}
}


//return- 0:Red 1:Green 2:Blue
int getColor(){

	int redValue=0,greenValue=0,blueValue=0;

	digitalWrite(s2, LOW);
	digitalWrite(s3, LOW);

	redValue = pulseIn(colorSensorOut, LOW);
	Serial.print("R= ");//printing name
	Serial.print(redValue);//printing RED color frequency
	Serial.print("  ");


	digitalWrite(s2, HIGH);
	digitalWrite(s3, HIGH);

	greenValue = pulseIn(colorSensorOut, LOW);
	Serial.print("G= ");//printing name
	Serial.print(greenValue);//printing RED color frequency
	Serial.print("  ");


	digitalWrite(s2, LOW);
	digitalWrite(s3, HIGH);

	blueValue = pulseIn(colorSensorOut, LOW);
	Serial.print("B= ");//printing name
	Serial.print(blueValue);//printing RED color frequency
	Serial.println("  ");
	delay(100);

	int redBlue = redValue - blueValue;
	int blueGreen = blueValue - greenValue;
	int redGreen = redValue - greenValue;

	if(redBlue<0){redBlue=-redBlue;}
	if(blueGreen<0){blueGreen=-blueGreen;}
	if(redGreen<0){redGreen=-redGreen;}

	if(redBlue<blueGreen && redBlue<redGreen){
		return 1;
	}
	else if(blueGreen<redBlue && blueGreen<redGreen){
		return 0;
	}
	else if(redGreen<redBlue && redGreen<blueGreen){
		return 2;
	}
}

void commandSlaveTo(int motion){
	Wire.beginTransmission(8);
	Wire.write(motion);
	Wire.endTransmission();
}
