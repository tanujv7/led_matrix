#include <FastLED.h>
#include <stdint.h>

#define LED_PIN     5
#define NUM_LEDS    32*32   // Change this to match your matrix size
#define BRIGHTNESS  200
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

int currentLED = 0;
int diagonal_tp_left_to_bt_right[] = { 0, 30, 34, 60, 68, 90, 102, 120, 136, 150, 170, 180, 204, 210, 238, 240};
int diagonal_bt_left_to_tp_right[] = {15, 17, 45, 51, 75, 85, 105, 119, 135, 153, 165, 187, 195, 221, 225, 255};

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  // Fill entire matrix with warm white
  // fill_solid(leds, NUM_LEDS, CRGB(255, 100, 10));
  

  int expList[] = { 256, 271, 511, 496};

  for(int8_t i = 0; i < sizeof(expList)/sizeof(int); i++) {
      currentLED = expList[i];
      leds[currentLED] = CRGB(255, 100, 10);
      
      FastLED.show();
}}

void loop() {

//  for (int8_t i = 0; i < sizeof(diagonal_tp_left_to_bt_right)/sizeof(int); i++) {
    
//    currentLED = diagonal_tp_left_to_bt_right[i];

//    leds[currentLED] = CRGB(255,100,10);
//    FastLED.show();
  
//    delay(50);
//  }

//  FastLED.clear();

//  for (int8_t j = 0; j < sizeof(diagonal_bt_left_to_tp_right)/sizeof(int); j++){
//    currentLED = diagonal_bt_left_to_tp_right[j];

//    leds[currentLED] = CRGB(255, 100, 10);

//    FastLED.show();

//    delay(50);
//  }

//  FastLED.clear();

//  for(int8_t k = 0; k < sizeof(diagonal_tp_left_to_bt_right)/sizeof(int); k++) {

//    currentLED = diagonal_tp_left_to_bt_right[k] + 255;

//    leds[currentLED] = CRGB(255, 100, 10);
    
//    FastLED.show();

 //   delay(50);

 // FastLED.clear();
 

}

