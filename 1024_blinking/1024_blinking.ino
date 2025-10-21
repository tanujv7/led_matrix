#include <FastLED.h>

#define NUM_LEDS 1024
#define COLOR_ORDER RGB
#define LED_TYPE WS2812B

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2812B, 5>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  FastLED.setCorrection(TypicalSMD5050);
  
  FastLED.setTemperature(Tungsten40W);
}

void loop() {

    leds[0] = CRGB(255,255,255); FastLED.show(); // CRGB VALUES ARE LIKE GREEN, RED, BLUE
}

