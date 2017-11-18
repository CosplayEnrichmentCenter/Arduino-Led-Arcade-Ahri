#include <FastLED.h>


/********BASIC SETTINGS********/

// the data pin for the NeoPixels
#define DATA_PIN 6

// How many LEDs we will be using, charge according to your needs
#define NUM_LEDS 60

//time for a full loop in milliseconds. e.g : 5000ms is 5s.
#define TIME_LOOP 15000

/* Section of the hue chart displayed on the LED strip.
 * Value must be between 0-255
 * Refer to the chart to adapt the section to your needs
 * Hue chart : https://raw.githubusercontent.com/FastLED/FastLED/gh-pages/images/HSV-rainbow-with-desc.jpg
 * Interesting values : 
 * 26 : Arcade Ahri
 * 256 : Full rainbow
 * 2048 : Just a pretty glowing, looks like something is living inside
 */

#define SECTION_SIZE 26

CRGB leds[NUM_LEDS];

//time variable
unsigned long time;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  //strip.setBrightness(40);
  Serial.begin(9600);
}

void loop() {
  renderLEDs();
}


void renderLEDs() {

  time = millis();
  //difference in time
  float deltaT = (float)(time%TIME_LOOP) / TIME_LOOP;
  //difference in position on the hue chart
  float deltaI = (deltaT*255);

  for (int i = 0; i < NUM_LEDS; i++) {

    //value is determined by adding to deltA the the relative position of the LED
    float value = deltaI+(((float)i/NUM_LEDS)*SECTION_SIZE);

    leds[NUM_LEDS-(i+1)]= CHSV(value,255,255);
  }
  FastLED.show();

}




