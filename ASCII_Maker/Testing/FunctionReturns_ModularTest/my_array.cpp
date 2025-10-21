#include "my_array.h"
#include <stdio.h>

ArrayData arr[] = {
  {2, {3,4}},
  {5, {6,7}}
};

int* array_return(int t) {
  for(int i = 0; i < 2; i++){
      if (arr[i].index == t){
        printf("\nMATCH FOUND\n");
        return arr[i].arrayd;
      }
      else {
        printf("\n NO MATCH FOUND \n");
      }
  }
  return nullptr;
};
