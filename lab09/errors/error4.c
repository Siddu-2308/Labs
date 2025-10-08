#include <stdio.h>
#include<stdlib.h>
int *a, *b;

void f(int x) {
  int *i=malloc(sizeof(int)*3);
  i[0] = x;
  i[1] = x + 1;
  i[2] = x + 2;
  a = i;
}  

void g(int x) {
  int *i=malloc(sizeof(int)*3);
  i[0] = x;
  i[1] = x + 1;
  i[2] = x + 2;
  b = i;
}  

int main() {
  f(1);
  printf("a = {%d,%d,%d}\n", a[0], a[1], a[2]);
  g(2);
  printf("a = {%d,%d,%d}\n", a[0], a[1], a[2]);
	free(b);free(a);
}

