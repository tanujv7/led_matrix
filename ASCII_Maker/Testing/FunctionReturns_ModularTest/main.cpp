#include <stdio.h>
#include "my_array.h"

int main() {

  int* my_receiving_list = array_return(5);

  for(int i = 0; i < 2; i++) {
    printf(" \nElements of the list are : - %d\n", my_receiving_list[i]);
  }

  return 0;
}
