//int sensorPin = A1;
int sensorPin2 = A2;
int sensorValue = 0;
int sensorValue2 = 0;
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
  //sensorValue = analogRead(sensorPin);
  sensorValue2 = analogRead(sensorPin2);
  //mappedValue = map(sensorValue,0,1023,-55,150);
 // float voltage = sensorValue * (5.0 / 1023.0);
  float voltageAD = (sensorValue2*1.0)/1024 * 5.0;
  float temperature = (voltageAD) * 100.0 - 273.15;
 // float resistance = (voltage*60000.0)/(5-voltage);
 // float temperature = voltage * 200 + 273.15;
  //Serial.print(sensorValue);
  //Serial.println(voltageAD);
  Serial.print(temperature);
  //Serial.print(",");
 // Serial.println("voltage");
 // Serial.print(voltage);
 // Serial.print(",");
  //Serial.println("resistance");
  //Serial.println(resistance);
}
