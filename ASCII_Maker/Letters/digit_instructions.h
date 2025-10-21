#ifndef DIGIT_INSTRUCTIONS_H
#define DIGIT_INSTRCUTIONS_H


#include <FastLED.h>

void light_on_rows(int row_start, int row_finish, int column);
void light_on_columns(int column_start, int column_finish, int row);

void letterT();

#endif
