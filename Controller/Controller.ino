#include <SPI.h>

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

int pinJoyX=0;
int pinJoyY=1;

int LedF=2;
int LedR=3;
int LedB=4;
int LedL=5;

RF24 radio(7, 8);
const byte address[6] = "00001";


/*------------Radio-----------------*/

bool sendData(int motion){
  radio.stopListening();
  bool success = radio.write(&motion, sizeof(motion));
  //delay(100);

  if(success){
    Serial.println("Successfully sent motion");
    Serial.println(motion);
    Serial.println("");
  }
  return success;
}
/*--------------------------------------*/
/*---------------------GET DIRECTION------------*/

int getDirection(){

  int joyX,joyY;

  joyX=analogRead(pinJoyX);
  joyY=analogRead(pinJoyY);

  if((joyX>=0&&joyX<=50))
    return 0;
  else if((joyX>=950&&joyX<=1030))
    return 2;
  else if((joyY>=0&&joyY<=50))
    return 1;
  else if((joyY>=950&&joyY<=1030))
    return 3;
  else
    return -1;
}

/*-----------------------------------------------*/

/*--------------------Display Direction----------*/

void displayDirection(int motion){

  switch(motion){
    case 0:digitalWrite(LedF,HIGH);delay(100);digitalWrite(LedF,LOW);break;
    case 1:digitalWrite(LedR,HIGH);delay(100);digitalWrite(LedR,LOW);break;
    case 2:digitalWrite(LedB,HIGH);delay(100);digitalWrite(LedB,LOW);break;
    case 3:digitalWrite(LedL,HIGH);delay(100);digitalWrite(LedL,LOW);break;
  }

}

/*-----------------------------------------------*/

void setup(){
  /*----LED PINS----*/
  pinMode(LedF,OUTPUT);
  pinMode(LedR,OUTPUT);
  pinMode(LedB,OUTPUT);
  pinMode(LedL,OUTPUT);

  /*-----TRAS------*/
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);

  Serial.begin(9600);

}

void loop(){

  /* Get Data from Pin And */

  int motion=getDirection();
  if(sendData(motion)&&motion!=-1)
    displayDirection(motion);

   // displayDirection(motion);

}
