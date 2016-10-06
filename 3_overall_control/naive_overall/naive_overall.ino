//AD590
int AD590_PIN = A2;
int AD590RAW = 0;
int mappedValue = 0;
#define resistor 5000
unsigned long time;

//thermistor
#include <math.h>
int THERMISTOR_pin = 7;
unsigned long duration_high;
unsigned long duration_low;
unsigned long period;
unsigned long frequency;
double temperature;
double a, b, c, d;

//CONTROL
//digital write to control cool down or heat up
int COOL_pin = 4;
int HEAT_pin = 8;
//decide heatup or cool down
//0 is cool down, 1 is heat up
#define COOL 1000
#define HEAT 1001
int MODE=COOL;

int set_temperature=30;

void setup() {
 pinMode(THERMISTOR_pin, INPUT);
 pinMode(COOL_pin, OUTPUT);
 pinMode(HEAT_pin, OUTPUT);

 //pinMode(3, OUTPUT);
 Serial.begin(9600);
 
}

void loop() {
   
    
    //reference temperature from AD590
    AD590RAW = analogRead(AD590_PIN);
    float voltageAD = (AD590RAW*1.0)/1024 * 5.0;
    float AD590_temperature = (voltageAD) * 100.0 - 273.15;
    Serial.print(AD590_temperature);
  

  
    //temperature from thermistor
    //now read frequency
    //analogWrite(3, 200);
    duration_high = pulseIn(THERMISTOR_pin, HIGH);
    duration_low = pulseIn(THERMISTOR_pin, LOW);
    period = duration_high + duration_low;
    frequency = 1000000/period;
    Serial.print(frequency);
  
    //y = a*exp(b*x) + c*exp(d*x)
    //where x is the temeprature, x is the frequency
    //a, b, c, d need to be copied from matlab
    temperature = a*exp(b*frequency) + c*exp(d*frequency);
    //ask DIDI how to print into csv format   


        switch(MODE){
        case COOL:
          if(temperature > set_temperature){
            digitalWrite(COOL_pin, HIGH);
        }
          else{
            digitalWrite(COOL_pin, LOW);
        }
          case HEAT:
            if(temperature < set_temperature){
            digitalWrite(HEAT_pin, HIGH);
        }
          else{
            digitalWrite(HEAT_pin, LOW);
        }
    }
    
    /* TESTING
    int test_temperature=20;
    //control system
     switch(MODE){
      case COOL:
        if(test_temperature > set_temperature){
          digitalWrite(COOL_pin, HIGH);
        }
        else{
          digitalWrite(COOL_pin, LOW);
        }
        case HEAT:
          if(test_temperature < set_temperature){
          digitalWrite(HEAT_pin, HIGH);
        }
        else{
          digitalWrite(HEAT_pin, LOW);
        }
    }
    Serial.print(COOL_pin);
    Serial.print(",");
    Serial.print(HEAT_pin);
    */


    

}
