#include <stdio.h>
#include "matrix_translation.h"

int main() {
  int M_ROWS = 16;
  int M_COLUMNS = 16;

  int LED_MATRIX[16][16] = {};

  matrix_map_generate(M_ROWS, M_COLUMNS, LED_MATRIX);

  for(int i = 0; i < M_ROWS; i++) {
    for (int j = 0; j < M_COLUMNS; j++) {
      printf("\nThe value of LED_MATRIX[%d][%d] is : - %d", i, j, LED_MATRIX[i][j]);
    }
  }

return 0;

}
