
int pin = 7;
int PWM_pin = 3;
int stable_counter=0;
int average_counter=0;
unsigned long int total_frequency=0;
int average_frequency=0;
bool flag = false;

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
