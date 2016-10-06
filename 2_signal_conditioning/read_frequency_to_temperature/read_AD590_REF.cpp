//AD590
int AD590_PIN = A2;
int AD590RAW = 0;
int mappedValue = 0;
#define resistor 5000
unsigned long time;

//thermistor
#include <math.h>
THERMISTOR_pin = 7;

void setup() {
 Serial.begin(9600);
 
}

void loop() {
    //reference temperature from AD590
    AD590RAW = analogRead(AD590_PIN);
    float voltageAD = (AD590RAW*1.0)/1024 * 5.0;
    float AD590_temperature = (voltageAD) * 100.0 - 273.15;
    Serial.print(AD590_temperature);

    //temperature from thermistor
    
    /*now read frequency*/
    duration_high = pulseIn(THERMISTOR_pin, HIGH);
    duration_low = pulseIn(THERMISTOR_pin, LOW);
    period = duration_high + duration_low;
    frequency = 1000000/period;

    //y = a*exp(b*x) + c*exp(d*x)
    //where x is the temeprature, x is the frequency
    //a, b, c, d need to be copied from matlab
    temperature = a*exp(b*x) + c*exp(d*x);
    //ask DIDI how to print into csv format


}