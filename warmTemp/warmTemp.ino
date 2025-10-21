#include <FastLED.h>
#include <stdint.h>

#define LED_PIN     5
#define NUM_LEDS    32*32   // Change this to match your matrix size
#define BRIGHTNESS  150
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define DIAGONAL_ARRAY_SIZE(given_array) sizeof(given_array)/sizeof(int)

CRGB leds[NUM_LEDS];



void transformArray(int led_diagonal_array[], int size_led_array) {

  for(int8_t i = 0; i < size_led_array; i++){

    led_diagonal_array[i] = led_diagonal_array[i] + 256;

    Serial.println("The value of led_diagonal_array[i] is : - ");
    Serial.print(led_diagonal_array[i]);

  }

}




void light_it_warm( int led_index_array[], int size_led_array ) {
  
  for(int8_t i = 0; i < size_led_array ; i++) {

    leds[led_index_array[i]] = CRGB(0, 255, 0);

    FastLED.show();

    delay(50);

}
}

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  
  // Fill entire matrix with warm white
  // fill_solid(leds, NUM_LEDS, CRGB(255, 100, 10));
  
  // FastLED.show();
}

void loop() {
  int currentLED = 0;
  int diagonal_tp_left_to_bt_right[] = { 0, 30, 34, 60, 68, 90, 102, 120, 136, 150, 170, 180, 204, 210, 238, 240};
  int diagonal_bt_left_to_tp_right[] = {15, 17, 45, 51, 75, 85, 105, 119, 135, 153, 165, 187, 195, 221, 225, 255};
  

  // MATRIX 1 - 16X16 -- START
  
  light_it_warm(diagonal_tp_left_to_bt_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));
  
  light_it_warm(diagonal_bt_left_to_tp_right, DIAGONAL_ARRAY_SIZE(diagonal_bt_left_to_tp_right));
  
  // MATRIX 1 - 16X16 -- END


  // MATRIX 2 - 16X16 -- START
  
  transformArray(diagonal_tp_left_to_bt_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));
  
  transformArray(diagonal_bt_left_to_tp_right, DIAGONAL_ARRAY_SIZE(diagonal_bt_left_to_tp_right));
  
  light_it_warm(diagonal_tp_left_to_bt_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));

  light_it_warm(diagonal_bt_left_to_tp_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));
  
  // MATRIX 2 - 16X16 -- END
  

  // MATRIX 3 - 16x16 -- START
  
  transformArray(diagonal_tp_left_to_bt_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));
  
  transformArray(diagonal_bt_left_to_tp_right, DIAGONAL_ARRAY_SIZE(diagonal_bt_left_to_tp_right));
  

  light_it_warm(diagonal_tp_left_to_bt_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));

  light_it_warm(diagonal_bt_left_to_tp_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));
  
  // MATRIX 3 - 16X16 -- END


  // MATRIX 4 - 16X16 -- START
  
  transformArray(diagonal_tp_left_to_bt_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));
  
  transformArray(diagonal_bt_left_to_tp_right, DIAGONAL_ARRAY_SIZE(diagonal_bt_left_to_tp_right));
  

  light_it_warm(diagonal_tp_left_to_bt_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));

  light_it_warm(diagonal_bt_left_to_tp_right, DIAGONAL_ARRAY_SIZE(diagonal_tp_left_to_bt_right));
  
  // MATRIX 4 - 16X16 -- END
  
  FastLED.clear();

  }




