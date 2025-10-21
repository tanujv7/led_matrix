#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    
    int diagonalElementsx16[16] = {};

    int8_t even_no = 1;

    for(int8_t i = 1; i < 16; i=i+2) {


            diagonalElementsx16[i] = 30 * even_no;
            diagonalElementsx16[i+1] = diagonalElementsx16[i] + 4 * even_no;

            even_no++;
        }

    for(int8_t j = 0; j < 16; j++) {
        printf("%d\n", diagonalElementsx16[j]);
    }

}
