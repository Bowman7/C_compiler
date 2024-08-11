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
//find sub
char* FindSubstring(int *left,int *right,char* file){
  printf("In substr\n");
  int l = *left;
  int r = *right;
  int size = strlen(file);
  l = r;
 
  while(!IsDelimiter(file[r]) && r<=size){
    r++;
  }
  char* temp = (char*)malloc((r-l+1)*sizeof(char));

  int count =0;
  for(int i = l;i<r;i++){
    temp[count] = file[i];
    count++;
  }
  temp[count]= '\0';
  //printf("Substring is: %s\n",temp);
  l = r;
  *left = l;
  *right = r;

  return temp;
}
bool IsKeyword(char* string){
  const char* keywords[] ={
    "auto","break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof","static",
    "struct","switch","typedef","union","unsigned","void","volatile","while"
  };
  for(int i=0;i<sizeof(keywords)/sizeof(keywords[0]);i++){
    if(strcmp(keywords[i],string) == 0){
      return true;
    }
  }
  return false;
}
bool CheckKeyword(char* substr,int* k_left,int* k_right){
  int l = *k_left;
  int r = *k_right;
  int size = strlen(substr);

  char* temp = (char*)malloc(size);
  int count =0;
  for(int i=0;i<size;i++){
    temp[count]=substr[i];
    //printf("Current string: %s\n",temp);

    if(IsKeyword(temp)){
      printf("It is a keyword: %s\n",temp);
    }
    count++;
    r++;
  }
  return false;
}
//print keywords
void PrintKeyword(char* file){
  int size = strlen(file);
  int left = 0;
  int right = 0;
  int k_left = 0;
  int k_right = 0;
  while(right<size && left<=right){
    if(IsDelimiter(file[right])){
      printf("%c is a delimiter\n",file[right]);
      right++;
      left = right;
    }
    else if(!IsDelimiter(file[right])){
      char* substr;
      substr = FindSubstring(&left,&right,file);
      printf("Substring after: %s\n",substr);
      //from substring check if is keyword
      if(CheckKeyword(substr,&k_left,&k_right)){
	printf("yes keyword");
      }
    }
    else{
      right++;
    }
   
    
    //if not a delimter then check if the substr is a keyword
  }
}

