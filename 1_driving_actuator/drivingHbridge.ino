#define OUTPUTPIN1 13
#define OUTPUTPIN2 12
#define TEMPERATURE A0
double voltage = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(OUTPUTPIN1, OUTPUT);
  pinMode(OUTPUTPIN2, OUTPUT):
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = analogRead(TEMPERATURE);
  double voltageAD = (voltage* 1.0) / 1024 * 5.0;
  double temperature = (voltageAD) *100 - 273.15;
  while(temperature < 50){
    //heating up
    digitalWrite(OUTPUTPIN1, HIGH);
    digitalWrite(OUTPUTPIN2, LOW);
  }
  while(temperature > 50 ){
    digitalWrite(OUTPUTPIN1, LOW);
    digitalWrite(OUTPUTPIN2, HIGH);
  }
}
