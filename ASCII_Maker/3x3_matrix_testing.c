#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  for(uint8_t i = 0; i < 13; i=i+4) {
    printf("%d ", i);
    for (uint8_t j = 1; j < 4; j++) {
      printf("%d ", i + j);
      }
    printf("\n");
      }
  return EXIT_SUCCESS;
  
}


