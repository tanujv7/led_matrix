#ifndef FONT_H
#define FONT_H


#include "config.h"

// Define maximum character size 

constexpr int FONT_WIDTH = 5;
constexpr int FONT_HEIGHT = 7;

// Each character stored as 5x7 bitmap

struct fontMap {
  char character;
  uint8_t bitmap[7];
};

uint8_t* getCharacterBitMap(char letter);


#endif
