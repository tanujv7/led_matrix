#include <FastLED.h>
#include "matrix_translation.h"
#include "digit_instructions.h"
#include "config.h"
#include <stdint.h>
#include "font.h"

#define LED_PIN     5

#define BRIGHTNESS  200
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[M_ROWS * M_COLUMNS];

char letterArray[26] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};


int LED_MATRIX[M_ROWS][M_COLUMNS];

void drawChar(char c, int x, int y, CRGB color){
    const uint8_t* characterMap = getCharacterBitMap(c);

    for(int i=0; i < 7; i++) {
      const uint8_t bits = characterMap[i];
      for(int j=4; j>=0; j--) {
        if(bits & ( 1 << j)){
          //Serial.println(" # ");
          leds[LED_MATRIX[x + i][y + (4-j)]] = color;
          FastLED.show();
        }
        //else {
          //Serial.println(" . ");
        //}
      }
      //Serial.println("\n");
    }

}

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, M_ROWS*M_COLUMNS);
  FastLED.setBrightness(BRIGHTNESS);
  
  Serial.begin(9600);
  matrix_map_generate(M_ROWS, M_COLUMNS, LED_MATRIX);
  

}

void loop() {
  
  Serial.println("\n\n");
  
  for(int i = 0; i < 26; i++) {
    drawChar(letterArray[i], 6,6, CRGB::Red);

    delay(100);

    FastLED.clear();

  };
}
