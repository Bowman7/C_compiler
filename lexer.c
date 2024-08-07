#include"lexer.h"

char* ReadFile(char* fileName){
  FILE *fptr;

  fptr = fopen(fileName,"rb");

  if(fptr == NULL){
    printf("Error loading file\n");
    exit(1);
  }

  //find the size of file
  fseek(fptr,0,SEEK_END);
  long size = ftell(fptr);
  fseek(fptr,0,SEEK_SET);

  char* file = (char*)malloc(size+1);
  file[size] = '\0';

  //now copy the file into file var
  fread(file,size,size,fptr);

  return file;
  
}
char* RemoveWhiteSpace(char* fileName){
  char* file;
  //read file
  file = ReadFile(fileName);
  printf("%s",file);

  //remove white spaces
  int size = strlen(file);
  char* file_ws = (char*)malloc(size);
  int count = 0;

  for(int i=0;i<size;i++){
    if(file[i] == ' '){
      //printf("white space");
    }else if(file[i] == '\n'){
      //printf("new line");
    }else if(file[i] == '\t'){
      
    }else{
      file_ws[count] = file[i];
      count++;
    }
  }
  file_ws[count] ='\0';

  return file_ws;
}
//check delimiter
bool IsDelimiter(char val){
  if(val == ' '|| val == '\t' || val == '\v' || val == '\n' || val == '\r'
     || val == '\f' || val == ',' || val == ';' || val == ':' || val == '.'
     || val == '(' || val == ')' || val == '{' || val == '}' || val == '['
     || val == ']' || val == '"' || val == '\'' || val == '#' || val == '+'
     || val == '-' || val == '*' || val == '/' || val == '%' || val == '='
     || val == '!' || val == '&' || val == '|' || val == '<' || val == '>'
     || val == '?'
     ){
    return true;
  }
  return false;

}
//print keywords
void PrintKeyword(char* file){
  int size = strlen(file);

  for(int i=0;i<size;i++){
    if(IsDelimiter(file[i])){
      printf("%c is a delimiter\n",file[i]);
    }
  }
}

