#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a;
  int b;
} thing;

void* newthing() {
  thing* t = (thing*)malloc(sizeof(thing));
  t->a=1;
  t->b=11;
  return t;
}

int main() {
  thing* t = newthing();
  printf("value: %d\n", t->a);
  printf("value: %d\n", t->b);
}
