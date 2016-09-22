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

  if(flag == false){
    //Serial.println("start stablisation");
    if(stable_counter<200){
       //Serial.println("STAB_COUNT +1");
      stable_counter++;
    }
    else{
      //stable_counter greater than 200
      // Serial.println("stablisation finished");
      flag=true;
     
    }
  }
  if(flag=true){
    //now start to take value in order to be able to take average
    //Serial.println("start taking average");
    if(average_counter<100){
      average_counter++;
      Serial.println(frequency);
      
      //Serial.println("TOT_FREQ +1 IS");
      total_frequency=total_frequency+frequency;
      //Serial.println(total_frequency);
    }
    else{
      //collection has finished
      //Serial.println("AVERAGE finished");
      
      average_frequency = total_frequency/100;
      //Serial.println(average_frequency);
      //Serial.println("FREQ NOW IS");
      Serial.println(frequency);
    }
  }
  }
