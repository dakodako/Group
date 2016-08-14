int analogPin = A0;
int analogSensor = 0;
float voltage = 0;
float current = 0;
float R1 = 1000;
float R2 = 0;
int Vin = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.println(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogSensor = analogRead(analogPin);
  voltage = (analogSensor)/1024 * Vin;
  current = voltage /R1;
  R2 = (5- voltage)/current;
  Serial.println(R2);
}
