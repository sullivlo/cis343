/**
* @Author: Louis Sullivan, Brendan Nahed
* @version 1.0
* @date Feb 11, 2018
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef GAME_H
#define GAME_H

void getMem(int* x, int* y, int*** grid);
void prompt(char* response);
void tokenizer(int* x, int* y, char** buffer, int*** grid);
void newBuff(int* x, int *y, int size, char** buffer, int** grid);
char* toArray(int num, char* numArr);
void freeMem(int *x, int *y, int*** grid);
int evolution(int* x, int* y, int*** grid);
void drawGrid(int* x, int* y, int** grid) ; 

#endif 