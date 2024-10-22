#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VARIABLES 3
#define MAX_PRODUCTION 100

int main(){

  char* val = malloc(100);
  scanf("%s",val);
  printf("string: %s\n",val);
  
  return 0;
}
