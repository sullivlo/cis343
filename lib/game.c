//
// Created by Louis Sullivan, Brendan Nahed on 1/30/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef GAME_H
#define GAME_H

int adjacent_to (int* x, int* y, int** grid, int i, int j);
void getMem(int* x, int* y, int*** grid);
void prompt(char* response);
void tokenizer(int* x, int* y, char** buffer, int*** grid);
void newBuff(int* x, int *y, char** buffer, int** grid);
int buffer_overRide(int* x, int* y, int* size, int** grid, char** buffer);
void freeMem(int *x, int *y, int*** grid);
int evolution(int* x, int* y, int*** grid);
void drawGrid(int* x, int* y, int** grid) ;

#endif 
