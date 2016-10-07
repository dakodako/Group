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
//double temperature;
//double a, b, c, d;

//CONTROL SYSTEM
int COOL_pin = 8;
int HEAT_pin = 13;

double temperature;
double a=16.38;
double b=0.0001782;
double c= -693.2;
double d= -0.0009077;


void setup() {
  pinMode(COOL_pin, OUTPUT);
  pinMode(HEAT_pin, OUTPUT);
 pinMode(THERMISTOR_pin, INPUT);
 Serial.begin(9600);
 
}

void loop() {
    //reference temperature from AD590
    AD590RAW = analogRead(AD590_PIN);
    float voltageAD = (AD590RAW*1.0)/1024 * 5.0;
    float AD590_temperature = (voltageAD) * 100.0 - 273.15;
    Serial.print(AD590_temperature);
    Serial.print(",");
    //temperature from thermistor
    
    /*now read frequency*/
    duration_high = pulseIn(THERMISTOR_pin, HIGH);
    duration_low = pulseIn(THERMISTOR_pin, LOW);
    period = duration_high + duration_low;
    frequency = 1000000/period;
   // temperature = a*exp(b*frequency) + c*exp(d*frequency);
    
    Serial.println(frequency);
    delay(250);



    digitalWrite(HEAT_pin, HIGH);

    
  /*
    //y = a*exp(b*x) + c*exp(d*x)
    //where x is the temeprature, x is the frequency
    //a, b, c, d need to be copied from matlab
    temperature = a*exp(b*frequency) + c*exp(d*frequency);
    //ask DIDI how to print into csv format
*/

}
