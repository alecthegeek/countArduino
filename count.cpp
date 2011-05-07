/*
  Count
 
 Turns on a row of LED on, then off repeatedly while counting in binary
 
 The circuit: http://www.oomlout.com/a/products/ardx/circ-02 
 
 Created Oct 2010
 By Alec Clews
*/

#include <WProgram.h>

#define MAX_LED  8 // How many LEDS (digits) in our binary readout
#define MAX_VALUE  pow(2,MAX_LED)
#define DELAYTIME 200
#define  LEDBASE 2  // First line for led array

typedef int led_state;

// A LED is a) attached to a PIN output and b) is off or on
typedef struct {int pinno; led_state state;} led_data_type;

inline led_data_type *flip(led_data_type *led,led_state to_state)
{
	led->state = to_state;
	digitalWrite(led->pinno,led->state);
#ifdef DEBUG
	Serial.print("FLipped LED on pin ");
	Serial.print(led->pinno);
	Serial.println(led->state ? " to HIGH":" to LOW");
#endif
	return led;
}

// Future use
inline led_data_type *toggle(led_data_type *led) { return flip(led, (LOW == led->state ? HIGH:LOW));}

// Increment a string of LED to the next binary number
void inc(led_data_type led[MAX_LED])
{
  for (int i=0; i < MAX_LED; i++)
    if (LOW == led[i].state)
    {
	flip(&(led[i]),HIGH);
	return;
    }
    else 
	flip(&(led[i]),LOW);
}

led_data_type leds[MAX_LED]; // The leds for our readout

// the loop() method runs over and over again,
// as long as the Arduino has power
void  loop(void)
{
  for (int i = 1 ; i< MAX_VALUE; i++) {
	  inc(leds);
#ifdef DEBUG
	  Serial.print("LED should display value");
	  Serial.println(i);
#endif
          delay(DELAYTIME);
  }
  delay(DELAYTIME);
  Serial.println("In loop");
}

// The setup() method runs once, when the program starts
void setup(void)
{                
  // initialize the digital pin as an output:
  for (int i=0; i<MAX_LED; i++) {
     leds[i].pinno = i + LEDBASE;  // Using Pins 2-9
     pinMode(leds[i].pinno, OUTPUT);     
     flip(&(leds[i]),LOW);
  }
#ifdef DEBUG
  Serial.begin(AVRDUDE_ARD_BAUDRATE);
  Serial.println("In setup");
#endif
}

