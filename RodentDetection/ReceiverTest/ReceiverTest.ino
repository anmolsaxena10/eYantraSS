/****************Header files**************/
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>

/*******************************************/
/*************Declarations********************/
RF24 radio(7, 8);
const byte address[6] = "00001";

int motion = -1; //motion initially at standby position

/********************************************/

/**Function to get data from radio module****/
int getData(int motion){
	radio.startListening();//starting the radio listener
	if(radio.available()){//checking the availability of radio
		radio.read(&motion, sizeof(motion));//reading the input from radio module
	}
  return motion;
}

/********************************************/

/**Setup Function***************/
void setup() {
	Serial.begin(9600);
	radio.begin();
	radio.openReadingPipe(0, address);
	radio.setPALevel(RF24_PA_MIN);
}
/*********************************/

/*******Loop******************/
void loop() {
	motion = getData(motion); //Call for the getData function to get transmited data

	Serial.print("Received motion: ");//Printing to serial monitor the received data
	Serial.println(motion);
	Serial.println("");
	
	delay(100);
}
/******************************/
