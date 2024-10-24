#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VARIABLES 2
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

  //printf("\nInt main: %c \n",production[0][0]);

  //print first set
  printf("First set: \n");
  for(int i=0;i<MAX_VARIABLES;i++){
    printf("string : %s\n",first_set[i]);
  }
  return 0;
}

void Find_FirstSet(char* production,char* first_set){
  //set variables 
  char variables[MAX_VARIABLES];
  for(int i=0;i<MAX_VARIABLES;i++){
    char temp = production[i*MAX_PRODUCTION];
    variables[i] = temp;
  }
  //print variables
   for(int i=0;i<MAX_VARIABLES;i++){
     printf("var :%c\n",variables[i]);
  }

  for(int i=0;i<MAX_VARIABLES;i++){
    int count=0;
    int k=2;
    while(production[i*MAX_PRODUCTION+k]!='\0'){
      k++;
      count++;
    }
    printf("Number of val in rhs: %d \n",count);

    //iterate the production

    char val;
    int f_pval = 0;
    val = production[i*MAX_PRODUCTION+2];
    first_set[i*MAX_PRODUCTION+f_pval] = val;
    f_pval++;

    for(int j=3;j<=count;j++){
      char val_cur = production[i*MAX_PRODUCTION+j];
      if(val_cur == '|'){
	char temp = production[i*MAX_PRODUCTION+j+1];
	first_set[i*MAX_PRODUCTION+f_pval] = temp;
	f_pval++;
      }
    }
  }
  //swap the var with teminals
  for(int i=0;i<MAX_VARIABLES;i++){
    int count =0;
    while(first_set[i*MAX_PRODUCTION+count]!='\0'){
      count++;
    }

    //now check if it is a var
    for(int k=0;k<count;k++){
      char val = first_set[i*MAX_PRODUCTION+k];
      printf("val first : %c\n",val);
      for(int i=0;i<MAX_VARIABLES;i++){
	if(variables[i] == val){
	  printf("It is a variable!\n");
	  //if variables push its first set val into the first set pos
	  printf("its first set are : \n");
	  printf("val :%c\n",first_set[i*MAX_PRODUCTION]);
	  //count val in a new char*
	  char* newSet;
	  
	}
      }
    }
    printf("Num of prod in first: %d\n",count);
  }

  printf("\n");
}

