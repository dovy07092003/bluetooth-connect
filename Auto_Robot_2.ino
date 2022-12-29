//Initialize Pins
int pinGreen = 10;
int pinYellow = 11;
int pinRed = 12;
int DSPinLeft = A0;
int DSPinRight = A1;

float DSSumRight;
float DSSumLeft;
float DSReadLeft;
float DSReadRight;
float DSMeanLeft;
float DSMeanRight;

//Set Motor Speeds
int LeftSpeed = 255;
int RightSpeed = 255;

//#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Motor Shield
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *LFMotor = AFMS.getMotor(2); // M1
Adafruit_DCMotor *RFMotor = AFMS.getMotor(1);// M2
Adafruit_DCMotor *LBMotor = AFMS.getMotor(3); // M1
Adafruit_DCMotor *RBMotor = AFMS.getMotor(4);
// If your bot is 4 wheel, please modify accordingly!!!!

void setup() {
  AFMS.begin();
  Serial.begin(9600);

  //Set LED Pins to Output
  pinMode(pinGreen, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinRed, OUTPUT);

  //Run Motors
  LMotor -> setSpeed(LeftSpeed);
  RMotor -> setSpeed(RightSpeed);
  LMotor -> run(FORWARD);
  RMotor -> run(FORWARD);
}

void loop() {
  //Update Motor Speed
  LMotor -> setSpeed(LeftSpeed);
  RMotor -> setSpeed(RightSpeed);

  DSSumRight = 0;
  DSSumLeft = 0;
  for (int i = 0; i < 200; i++) {
    DSReadRight = analogRead(DSPinRight);
    DSReadLeft = analogRead(DSPinLeft);
    DSSumRight = DSSumRight + DSReadRight;
    DSSumLeft = DSSumLeft + DSReadLeft;
    //Serial.println(DSReadRight);
  }
  DSMeanRight = DSSumRight / 200;
  DSMeanLeft = DSSumLeft / 200;
  Serial.println(DSMeanRight);
  //If Right Sensor Closer to Wall Then Turn Left. Else Turn Right
  if (DSMeanRight > 500) {
    LeftSpeed = 80;
    RightSpeed = 150;
    delay(10);
    Serial.println("Right");
  }
  else if (DSMeanLeft > 500) {
    LeftSpeed = 150;
    RightSpeed = 80;
    delay(10);
    Serial.println("Left");
  }
  else {
    LeftSpeed = 150;
    RightSpeed = 150;
  }
}
