int pinArray[] = {2, 3, 4, 5, 6, 7};
int count = 0;
int timer = 100;

int sensorPin = A0;//analog input Pin in charge of the brightness of the LEDs
int sensorPin2 = A1;// analog input Pin in charge of the speed of the LED Patterns
int sensorValue=0;
int mappedValue=0;
int sensor2Value = 0;
int mapped2Value = 0;


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
  	sensor2Value = analogRead(sensorPin2);
  	mappedValue = map(sensorValue, 0, 1023, 0, 255);
  	mapped2Value = map(sensor2Value,0,1023,0,1000);
  	Serial.println (mappedValue);
  	Serial.println (mapped2Value);

  for (count=0;count<6;count++) {
    analogWrite(pinArray[count], sensorValue);
   //digitalWrite(pinArray[count], HIGH);
  // delay(timer);
   delay(mapped2Value);
   digitalWrite(pinArray[count], LOW);
   //delay(timer);
   delay(mapped2Value);
  }
  for (count=5;count>=0;count--) {
   analogWrite(pinArray[count], sensorValue);
   //delay(timer);
   delay(mapped2Value);
   digitalWrite(pinArray[count], LOW);
  // delay(timer);
  delay(mapped2Value);
  }
}
