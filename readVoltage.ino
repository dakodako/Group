int sensorPin = A0;
int sensorValue = 0;
unsigned long time;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Time: ");
  time = micros();
  Serial.println(time);
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
}
