
int pin = 7;
int PWM_pin = 3;


unsigned long duration_high;
unsigned long duration_low;
unsigned long period;
unsigned long frequency;
 
void setup()
{
  pinMode(pin, INPUT);
  Serial.begin (9600);
}

void loop()
{
  duration_high = pulseIn(pin, HIGH);
  duration_low = pulseIn(pin, LOW);
  period = duration_high + duration_low;
  frequency = 1000000/period;
  //Serial.println(frequency);
}
