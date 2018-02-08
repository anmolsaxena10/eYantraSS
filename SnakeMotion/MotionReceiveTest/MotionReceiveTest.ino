#include <Wire.h>
#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4; 
Servo s5;
Servo s6;
Servo s7;

int counter = 0;
float lag = .5712;
int frequency = 1;
int amplitude = 40;
int rightOffset = 5;
int leftOffset = -5;
int offset = 6;
int delayTime = 7;
int startPause = 5000;
int test = -3;


void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);

  /*--------------------------------------------------------------------*/
  Wire.onReceive(receiveEvent);//I dont know what is this so figure out
  /*-------------------------------------------------------------------*/
  Serial.begin(9600);

  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
  s5.attach(6);
  s6.attach(7);
  s7.attach(8);

  s1.write(90+amplitude*cos(3*lag));
  s2.write(90+amplitude*cos(2*lag));
  s3.write(90+amplitude*cos(1*lag));
  s4.write(90+amplitude*cos(0*lag));
  s5.write(90+amplitude*cos(-1*lag));
  s6.write(90+amplitude*cos(-2*lag));
  s7.write(90+amplitude*cos(-3*lag));

  delay(startPause);
}

void receiveEvent(int howMany){
  int motion = Wire.read();
  Serial.println(motion);
}


void loop() {
  // put your main code here, to run repeatedly:

  //forword direction
  if(motion==0){

    for(counter = 0; counter < 360; counter += 1)  {

      delay(delayTime);
      s1.write(90+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));
      s7.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));

    }
  }else if(motion==2){

   for(counter = 360; counter > 0; counter -= 1)  {
      delay(delayTime);
      s1.write(90+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));
      s7.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));

    }
   }else if (motion==1){
// Ramp up turn offset
    for(counter = 0; counter < 10; counter += 1)  {
      delay(delayTime);
      s1.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
      s7.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    }
// Continue right turn
    for(counter = 11; counter < 350; counter += 1)  {
      delay(delayTime);
      s1.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
      s7.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    }
// Ramp down turn offset
    for(counter = 350; counter < 360; counter += 1)  {
      delay(delayTime);
      s1.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
      s7.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    }
  }else if (motion==3){
// Ramp up turn offset
    for(counter = 0; counter < 10; counter += 1)  {
      delay(delayTime);
      s1.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
      s7.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    }
// Continue left turn
    for(counter = 11; counter < 350; counter += 1)  {
      delay(delayTime);
      s1.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
      s7.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    }
// Ramp down turn offset
    for(counter = 350; counter < 360; counter += 1)  {
      delay(delayTime);
      s1.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
      s7.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    }
  }

}
