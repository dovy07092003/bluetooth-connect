int pinds = A1;
int dsRead;
float DSsum;
float DSmean;


void setup() {
  // put your setup code here, to run once:
pinMode(pinds, INPUT);
Serial.begin(9600); // the speed of communication
}

void loop() {
  // put your main code here, to run repeatedly:
  DSsum=0; //reset
  for(int i=0; i<100; i++){
  dsRead=analogRead(pinds);
  DSsum= DSsum + dsRead;//sum all the data points
  }
  DSmean=DSsum/100;//find the average of the sum
//DSV=dsRead*(3.3)/1023;
Serial.println(DSmean);
}
