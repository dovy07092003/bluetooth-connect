
int pbs=6;
int bsRead;
int pinDS =A0;
float DSread;
float sumread;
float meanread;
#include<Wire.h>
#include<Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS=Adafruit_MotorShield();
Adafruit_DCMotor *LMotor = AFMS.getMotor(3);
Adafruit_DCMotor *RMotor = AFMS.getMotor(4);
void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
pinMode(pbs, INPUT);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  sumread=0;
  for(int i=0; i<100; i++){
  DSread=analogRead(pinDS);
  sumread=sumread+DSread;
  }
  meanread=sumread/100;
  joe();
  if(meanread<126 && bsRead==1){
   LMotor -> run (FORWARD);
   LMotor -> setSpeed(255);
   RMotor -> run (FORWARD);
   RMotor -> setSpeed(255);
  } else if(meanread < 126 && bsRead==0){
   LMotor -> run (FORWARD);
   LMotor -> setSpeed(255/2);
   RMotor -> run (FORWARD);
   RMotor -> setSpeed(255/2);
    }else{
   LMotor -> run (FORWARD);
   LMotor -> setSpeed(255);
   RMotor -> run (FORWARD);
   RMotor -> setSpeed(255);
   }
    
} 

//User defined function
void joe (){
bsRead=digitalRead (pbs);
Serial. println(bsRead);
delay(100);
}
