#include<stdio.h>
#include<stdlib.h>

#include"lexer.h"

int main(){

  //read the text from a file
  FILE *fptr;
  char fileName[100];

  printf("Enter filename: ");
  scanf("%s",fileName);

  char* file;
  //remove white space
  file = RemoveWhiteSpace(fileName);
  //printf("file now:\n%s",file);
  PrintKeyword(file);
  
  return 0;
}
