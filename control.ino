const long double p1 = -8.766e-13;
const long double p2 = 1.9e-08;
const long double p3 = -0.0001551;
const long double p4 = 0.5783;
const long double p5 = -807.4;
const long double q1 = 4.906e-13;
const long double q2 = -9.443e-09;
const long double q3 = 6.947e-05;
const long double q4 = -0.2192;
const long double q5 = 250.9;

int mode;
double temperature = 0;

const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin2 = 4;
//const int ledPin =  13;      // the number of the LED pin

#define HEAT 1
#define COOL 0
// variables will change:
int buttonState = 0; // variable for reading the pushbutton status
int buttonState2 = 0;
// 9 shengwen
// 10 jiangwen
void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if(buttonState == HIGH){
    mode = HEAT;
  }
  if(buttonState2 == HIGH){
    mode = COOL;
  }
  // put your main code here, to run repeatedly:
  long int duration_high = pulseIn(7, HIGH);
  long int duration_low = pulseIn(7, LOW);
  long int period = duration_high + duration_low;
  long int frequency = 1000000/period;
//  temperature = p1 * pow(frequency,4) + p2 * pow(frequency,3) + p3 * pow(frequency,2) + p4 *frequency + p5;
  Serial.println(frequency);
  Serial.println((double)temperature_heat);
  
  double set = map(analogRead(A0),0,1024,5,45);
  Serial.println(analogRead(A0));
 
  if(mode == HEAT){
    temperature = p1 * pow(frequency,4) + p2 * pow(frequency,3) + p3 * pow(frequency,2) + p4 *frequency + p5;
    if(temperature < set){
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    } else {
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    }
  }
  if(mode == COOL){
    temperature = q1 * pow(frequency,4) + q2 * pow(frequency,3) + q3 * pow(frequency,2) + q4 *frequency + q5;
    if(temperature > set){
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
    } else {
      digitalWrite(9,LOW);
      digitalWrite(9,LOW);
    }
  }
  
  delay(500);
}
