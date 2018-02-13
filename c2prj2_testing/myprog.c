#include <stdio.h>
#include <stdlib.h>

struct rectangle{
  int x;
  int y;
};

typedef struct rectangle rect_t;

int main(){
  rect_t recta;
  recta.x=4;
  recta.y=5;
  int area= recta.x*recta.y;
  printf("Area is %d", area);
  return EXIT_SUCCESS;
}
    
 
