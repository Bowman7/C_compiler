#ifndef LEXER_H
#define LEXER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char* RemoveWhiteSpace(char*);
char* ReadFile(char*);
void PrintKeyword(char*);
char* FindSubstring(int*,int*,char*);
bool CheckKeyword(char*,int*,int*);
bool IsKeyword(char*);
#endif
