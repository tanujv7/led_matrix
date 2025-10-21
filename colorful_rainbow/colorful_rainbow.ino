#include <FastLED.h>

#define LED_PIN 5

#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 32

#define NUM_LEDS (MATRIX_WIDTH * MATRIX_HEIGHT)

#define BRIGHTNESS 64
#define COLOR_ORDER GRB

#define LED_TYPE WS2812B


CRGB leds[NUM_LEDS];


// # If your matrix is serpentine, define this as true

#define SERPENTINE_LAYOUT true

uint16_t XY(uint8_t x, uint8_t y) {
  uint16_t i;

  if(SERPENTINE_LAYOUT) {
    if (y % 2 == 0) {
      // even rows left-to-right

      i = y * MATRIX_WIDTH + x;

    } else {

      // odd rows right-to-left

      i = y * MATRIX_WIDTH + ( MATRIX_WIDTH - 1 - x);
    }

  } else {

    // standard progressive layout

    i = y * MATRIX_WIDTH + x;
  }

  return i;

}


void setup() {
  
  delay(1000);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Rainbow animation
  
  static uint8_t hue = 0;

  for (uint8_t y = 0; y < MATRIX_HEIGHT; y++) {
    for(uint8_t x= 0; x < MATRIX_WIDTH; x++) {
      leds[XY(x, y)] = CHSV(hue + x * 2 + y * 2, 255, 255);
    }
  }

  FastLED.show();
  hue++;
  delay(30);
}
