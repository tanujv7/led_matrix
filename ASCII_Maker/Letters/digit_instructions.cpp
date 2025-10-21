#include "digit_instructions.h"
#include "matrix_translation.h"
#include "config.h"
#include <FastLED.h>


extern CRGB leds[];	// leds declared in Letters.ino

extern int LED_MATRIX[M_ROWS][M_COLUMNS];  // shared from Letters.ino

void light_on_rows(int row_start, int row_finish, int column) {
  for(int i = row_start; i < row_finish + 1; i++) {
    leds[LED_MATRIX[i][column]] = CRGB(255, 100, 10);
  }
}

void light_on_columns(int column_start, int column_finish, int row) {
  for(int i = column_start; i < column_finish+1; i++) {
    leds[LED_MATRIX[row][i]] = CRGB(255,100,10);
  }
}


void letterT() {
  delay(1000);

  light_on_columns(2,14,2);
  light_on_columns(2,7,4);
  light_on_columns(9,14,4);
  light_on_columns(7,9,13);

  light_on_rows(4,13,7);
  light_on_rows(4,13,9);
  light_on_rows(2,4,2);
  light_on_rows(2,4,14);
}


