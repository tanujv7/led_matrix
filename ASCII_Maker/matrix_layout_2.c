#include <stdio.h>
#include <stdlib.h>


int main() {

  int M_ROWS = 16;
  int M_COLUMNS = 16;

  int LED_MATRIX[16][16] = {};

  // Initial Filler .... for example. 0 - 9 , [9-0] = 9; is the filler
  int A_FILL = M_ROWS * 2 - 1;
  int ODD_COUNTER = 1; // Odd counter for the third value, which increments by 2 in loop 1.

  int A_VAL = 0;      // To store .. current value or prev value
  int COLUMN_COUNTER = 0; // To count how many columns have been done ..

  for (int j = 0; j < M_ROWS; j++) {

    A_VAL = j;
  // For Columns
    for(int i = j; i < M_COLUMNS+j; i++) {
      if(COLUMN_COUNTER == M_COLUMNS) {
        break;
      }

      printf(" %d ", A_VAL );
      
      LED_MATRIX[j][COLUMN_COUNTER] = A_VAL;

      COLUMN_COUNTER = COLUMN_COUNTER + 1;

      A_VAL = A_FILL + A_VAL;

      if(COLUMN_COUNTER == M_COLUMNS) {
        break;
      }

      printf(" %d ", A_VAL);

      LED_MATRIX[j][COLUMN_COUNTER] = A_VAL;

      A_VAL = A_VAL + ODD_COUNTER;

      COLUMN_COUNTER++;

  }
    printf("\n");

    A_FILL = A_FILL - 2;
    COLUMN_COUNTER = 0;

    // printf("\nINCREASED THE ODD_COUNTER\n");
    // printf("\n IT'S VALUE IS : - %d\n",ODD_COUNTER);

    ODD_COUNTER = ODD_COUNTER + 2;
  }

  return EXIT_SUCCESS;
}
