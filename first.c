#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VARIABLES 3
#define MAX_PRODUCTION 100

void Find_FirstSet(char* production,char* first_set);
int main(){
  
  char production[MAX_VARIABLES][MAX_PRODUCTION];
  char first_set[MAX_VARIABLES][MAX_PRODUCTION];
  
  for(int i=0;i<MAX_VARIABLES;i++){
    char* val=malloc(100);
    printf("Enter production %d: ",i);
    scanf("%s",val);
    strcpy(production[i],val);
  }
  
  //print production
  for(int i=0;i<MAX_VARIABLES;i++){
    printf("string : %s\n",production[i]);
  }

  //find first set
  Find_FirstSet(production[0],first_set[0]);

  printf("\nInt main: %c \n",production[0][0]);

  //print first set
  printf("First set: \n");
  for(int i=0;i<MAX_VARIABLES;i++){
    printf("string : %c\n",first_set[i][0]);
  }
  return 0;
}

void Find_FirstSet(char* production,char* first_set){
  printf("first of prod 0: %c",production[0]);

  for(int i=0;i<MAX_VARIABLES;i++){
    //printf("\nfirst of %d: %c",i,production[i*MAX_PRODUCTION]);
    char val;
    val = production[i*MAX_PRODUCTION];
    first_set[i*MAX_PRODUCTION] = val;
  }
  //chage first val
  production[0] = 'X';

  
}
