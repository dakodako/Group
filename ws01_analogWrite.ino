int pinArray[] = {2, 3, 4, 5, 6, 7};
int count = 0;
int timer = 100;

int sensorPin = A0;//analog input Pin
int sensorValue=0;
int mappedValue=0;


void setup(){
    Serial.begin (9600);
  for (count=0;count<6;count++) {
    pinMode(pinArray[count], OUTPUT);
  }

  //no need for analog setup
}

void loop() {
    //for the potentialmeter it should be 0 to 1024
    //USED MAP
    sensorValue = analogRead(sensorPin);
  	mappedValue = map(sensorValue, 0, 1024, 0, 255);
    Serial.println (mappedValue);

  for (count=0;count<6;count++) {
    analogWrite(pinArray[count], sensorValue);
   //digitalWrite(pinArray[count], HIGH);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer);
  }
  for (count=5;count>=0;count--) {
   analogWrite(pinArray[count], sensorValue);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer);
  }
}