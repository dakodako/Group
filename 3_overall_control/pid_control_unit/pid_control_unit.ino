/********************************************************
 * PID Adaptive Tuning Example
 * One of the benefits of the PID library is that you can
 * change the tuning parameters at any time.  this can be
 * helpful if we want the controller to be agressive at some
 * times, and conservative at others.   in the example below
 * we set the controller to use Conservative Tuning Parameters
 * when we're near setpoint and more agressive Tuning
 * Parameters when we're farther away.
 ********************************************************/

#include <PID_v1.h>

#define SET_PIN_INPUT A0
#define PIN_OUTPUT_COOL 3
#define PIN_OUTPUT_HEAT 5
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

const int INPUTPIN = 7;


//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Define the aggressive and conservative Tuning Parameters
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;

//Specify the links and initial tuning parameters
#define HEAT 2
#define COOL 1
PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);
int mode;
// Pin Assignments
//const int INPUTPIN 7;
//const int SETPOINTPIN A0;
// frequency reading
unsigned long duration_high;
unsigned long duration_low;
unsigned long period;
unsigned long frequency;
double readTemperature(double frequency){
  double result;
  if(mode == COOL){
    result = q1 * pow(frequency,4) + q2 * pow(frequency,3) + q3 * pow(frequency,2) + q4 *frequency + q5;
  } else {
    result = p1 * pow(frequency,4) + p2 * pow(frequency,3) + p3 * pow(frequency,2) + p4 *frequency + p5;
  }
  return result;
}
void setup()
{
  //initialize the variables we're linked to
  duration_high = pulseIn(INPUTPIN, HIGH);
  duration_low = pulseIn(INPUTPIN, LOW);
  period = duration_high + duration_low;
  frequency = 1000000/period;
  mode = HEAT;
  double temperature = ((readTemperature(frequency)-5)/40)*255;
  
  Input = ((temperature - 5)/40) * 255;
  Setpoint = (((20-5) * 1.0)/40) * 255;
  
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255,255);
  //myPID.SetSampleTime(1000);
}

void loop()
{
  //Input = analogRead(PIN_INPUT);
  double temperature = readTemperature(frequency);
  Input = ((temperature - 5)/40) * 255;
  Setpoint = analogRead(SET_PIN_INPUT);
  double gap = abs(Setpoint-Input); //distance away from setpoint
  
  if (gap < 10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID.SetTunings(consKp, consKi, consKd);
  }
  else
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID.SetTunings(aggKp, aggKi, aggKd);
  }
  if(Input - Setpoint < 0){
    mode = COOL;
  } else {
    mode = HEAT;
  }
  myPID.Compute();
  Serial.println("output = %d\n", Output);
  if(mode == COOL && Output < 0){
    analogWrite(PIN_OUTPUT_COOL, -Output);
    analogWrite(PIN_OUTPUT_HEAT, 0);
  } else if(mode == HEAT && Output >= 0){
    analogWrite(PIN_OUTPUT_HEAT, Output);
    analogWrite(PIN_OUTPUT_COOL, 0);
  }
  
}


