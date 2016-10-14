#include <Bridge.h>
#include <HttpClient.h>
#include <Console.h>
 /*TEST CONSOLE AND DWEET*/
int analogIn = A0; 
int analogVal = 0; 
int analogIn1 = A1; 
int analogVal1 = 0;

void setup() {
  // Bridge takes about two seconds to start up
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  Console.begin();
    // Wait for Console port to connect
  while (!Console);
  Console.println("CONSOLE ON");//Data flow: Arduino --> Yun Shield --> Arduino IDE
  digitalWrite(13, HIGH);
}

void loop() {
// Initialize the client library
  analogVal = analogRead(analogIn);
  analogVal1 = analogRead(analogIn1);
  if (Console.available() > 0) {
    Console.println(analogVal);
  }
  HttpClient client;
  // Make a HTTP request:To send analog input values of A0 and A1
  //interfacing with dweet
  //access by https://dweet.io/follow/YUN_ANALOG_IN_DWEETING_2
  client.get("http://www.dweet.io/dweet/for/YUN_ANALOG_IN_DWEETING_2?AnalogInput_A0="+String(analogVal)
  +"&AnalogInput_A1="+String(analogVal1));
  while (client.available()) {
  char c = client.read();
  }
  //Console.flush();
  //delay(1000);
}
