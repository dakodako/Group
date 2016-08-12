int sensorPin = A0;
int sensorValue = 0;
int mappedValue = 0;
#define resistor 5000
unsigned long time;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  //time = micros();
  sensorValue = analogRead(sensorPin);
  //mappedValue = map(sensorValue,0,1023,-55,150);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage/resistor) * (10^6) + 273.15;
  Serial.println(sensorValue);
  Serial.println(voltage);
}
