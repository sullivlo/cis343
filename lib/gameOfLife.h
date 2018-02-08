//
// Created by Louis Sullivan, Brendan Nahed on 1/30/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H


int getMem(int** Mem);
void drawGrid(int x, int y, int* grid[x][y]) ;
int main(int argc,char* argv[]);

#endif 
