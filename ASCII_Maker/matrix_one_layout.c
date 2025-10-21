#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t MATRIX_ROWS = 6;
uint8_t MATRIX_COLUMNS = 5;


int main() {
  
  uint16_t prev_one = 0;
  
  uint16_t STARTER_VALUE = MATRIX_ROWS*2 - 1;

  uint16_t tempVariable = 0;
  
  int odd_counter = 1;

  for (uint16_t j = 0; j < MATRIX_ROWS; j++) {
    printf("  %d ", j);

    tempVariable = j;
    
    for(uint16_t i = 1; i < MATRIX_COLUMNS-1 ; i++) {
       
      prev_one = STARTER_VALUE  + tempVariable +  prev_one;

      tempVariable = 0;

      printf("  %d ", prev_one);
      
      
      prev_one = prev_one + odd_counter;
      printf("  %d ", prev_one);

    }

    printf("\n");

    prev_one = 0;

    odd_counter = odd_counter + 2;
  
    STARTER_VALUE = STARTER_VALUE - 2;

  }

  return EXIT_SUCCESS;
}
