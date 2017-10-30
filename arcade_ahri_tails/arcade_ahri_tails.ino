#include <Adafruit_NeoPixel.h>

struct RGB
{
  float red;
  float green;
  float blue;
};

RGB table[3];

// the data pin for the NeoPixels
int neoPixelPin = 6;

// How many NeoPixels we will be using, charge accordingly
const int numPixels = 60;

// Instatiate the NeoPixel from the ibrary
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

//time variable
//unsigned long time;

// a pre-processor macro
#define DELAY_TIME (10)

int timeLoop = 12500; //time for a full loop


void setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
  //strip.setBrightness(40);
  //Serial.begin(9600);
}

void loop() {
  renderLEDs();
}

// Turns all the NeoPixels off
void allOff() {
  strip.clear();
  strip.show();
}

// turn 1/3 of strip different colors. this is a crude, but effective way to do this.
void renderLEDs() {

  unsigned int time = millis();
  unsigned int deltaT = time % timeLoop;
  unsigned int deltaI = ((float)time / (float)timeLoop) * 255;

  for (int i = 0; i < numPixels; i++) {

    int value = (int)(deltaI + (((float)i / (float)numPixels) * (255.0 / 15))) % 255;
    strip.setPixelColor(numPixels - (i + 1), Wheel(value));
  }
  strip.show();

}



// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}



