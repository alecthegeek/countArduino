/*
  Count
 
 Turns on a row of LED on, then off repeatedly while counting in binary
 
 The circuit:
 
 
 Created Oct 2010
 By Alec Clews
*/

#include <WProgram.h>

#define max_LED  7 // How many LEDS (digits) in our binary number
#define delayTime 500 // 1/2 seconds
#define  LEDBASE 2;  // First line for led array

int leds[max_LED]; // The lines for each led
int ledState[max_LED]; // The lines for each led

void inc(const int *linesToToggle)
{
  for (int i=0; i<max_LED; i++)
  {
    if (0 == ledState[i])
    {
      digitalWrite(linesToToggle[i],HIGH);
      ledState[i] = 1;
      return;
    } 
    else
    {
      digitalWrite(linesToToggle[i],LOW);
      ledState[i] = 0;
    }
  } 
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void  loop(void)
{
  for (int i = 0 ; i<= (pow(2,max_LED)); i++)
	  inc(leds);
  delay(delayTime);
}


// The setup() method runs once, when the sketch starts
void setup(void)
{                
  // initialize the digital pin as an output:
  // pinMode(ledPin, OUTPUT);     
  for (int i=0; i<max_LED; i++)
  {
     leds[i] = i + LEDBASE;
     ledState[i] = 0;
     pinMode(leds[i], OUTPUT);     
     digitalWrite(leds[i], LOW);
  }
}
