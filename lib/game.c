// Author: Louis Sullivan, Brendan Nahed
//
//
//



//allocate memory to the heap
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "gameOfLife.h"
#include "file_utilities.h"
#include "game.h"



//Display the grid to the termanal window
//drawGrid take a x, horizontal and a y, vertical to build a 2D grid
void drawGrid(int* x, int* y, int** grid) {
    for (int i = 0; i < *x; i++) {
        for (int j = 0; j < *y; j++) {
            if(*(*(grid+i)+j) != -1)
                printf("%d ", *(*(grid+i)+j));
            else
                printf("- ");
        }
        printf("\n");
    }
 printf("\n");
}

void newBuff(int* x, int *y, int size, char** buffer, int** grid){
    char* newLine= "\n";
    *buffer = malloc(size* sizeof(int));
    printf("%d\n", (*(*(grid+0)+0)));
    char* temp = malloc(sizeof(int));
    snprintf(temp, sizeof(temp), "%d ", (*x));
    strncat(*buffer, temp, size);
    free(temp);
    temp = malloc(sizeof(int));
    snprintf(temp, sizeof(temp), "%d ", (*y));
    strncat(*buffer, temp, size);
    free(temp);
    strncat(*buffer, newLine, size);
    for(int i = 0; i < *x; ++i){
        for(int j = 0; j < *y; ++j){
            temp = malloc(sizeof(int));
            snprintf(temp, sizeof(temp), "%d ", (*(*(grid+i)+j)));
            strncat(*buffer, temp, size);
            free(temp);
        }
        if(i+1<*x){
            strncat(*buffer, newLine, size);
        }
    }
    
}

void freeMem(int* x, int* y, int*** grid){
  //free columns
    for(int i = (*y); i >= 0;--i){
        free((*grid)[i]);
    }
    
 free ((*grid));
}

void getMem(int* x, int* y, int*** grid){
    *grid = (int**) malloc((*x) * sizeof(int*));
    for(int i =0 ; i < *y; ++i) {
        (*grid)[i] = (int*) malloc((*y) * sizeof(int));
    }
}
/**
* tokenizer
* @parm int* x - the amount of rows in the grid.
* @parm int* y - the amount of columns in the grid.
* @parm char** buffer - pointer to a char array.
* @parm int*** grid - pointer to the two dementional
* integer array that holds the world.
* tokenizer creates tokens of each integer in the
* buffer and the points them into the grid.
*/
void tokenizer(int* x, int* y, char** buffer, int*** grid){
    *x = atoi(strtok(*buffer, " \n"));
    *y = atoi(strtok(NULL, " \n"));
    printf("int x = %d, int y = %d\n",*x, *y );
    //Creates the grid and populates the grid.
    // Malloc the grid.
    *grid = (int**) malloc((*x) * sizeof(int*));
    for(int i =0 ; i < *y; ++i) {
        (*grid)[i] = (int*) malloc((*y) * sizeof(int));
    }
    for(int i = 0; i < *x; i++){
        for(int j = 0; j < *y; j++){
            (*(*(*grid+i)+j)) = atoi(strtok(NULL, " \n"));
        }
    }
}

/**
* prompt
* @parm char* response - a pointer to a char.
* prompt is the message displayed to the user
* after each iteration of the game.
*/
void prompt(char* response){
    *response = ' ';
    printf("\n");
    printf("Would you like to save this file: S\n");
    printf("Would you like to load a file: L\n");
    printf("Would you like to quit the game?: Q\n");
    printf("Or to continue playing. P\n");
    scanf("%s", response);
}


/**
* adjacent_to
* @parm int* x - the amount of rows in the grid.
* @parm int* y - the amount of columns in the grid.
* @parm int*** grid - pointer to the two dementional
* integer array that holds the world.
* @parm int i - the current row on the grid.
* @parm int j - the current column on the grid.
* @return count - count in the number of live neighbors
* to the current position.
* Evolutions evoles the grid to the next generation.
*/
int adjacent_to (int* x, int* y, int** grid, int i, int j) {
    //Count keeps track of the adjacent living cells.
    int count = 0;
    //Checks around the Cell
    for (int k=i-1; k<=i+1; k++) {
        for (int l=j-1; l<=j+1; l++){
            if((-1<k && -1<l) && (*x>k && *y>l)){
                if(*(*(grid+k)+l)==1){
                   count++;
                }
                 
            }
        }
    }
    if(*(*(grid+i)+j)==1){
        count--;
    }
    return count;
}


/**
* evolution
* @parm int* x - the amount of rows in the grid.
* @parm int* y - the amount of columns in the grid.
* @parm int*** grid - pointer to the two dementional
* integer array that holds the world.
* @return 0 - to end the method.
* Evolutions evoles the grid to the next generation.
*/
int evolution(int* x, int* y, int*** grid){
    int** tempGrid;
    getMem(x, y, &tempGrid);
    for(int i = 0; i < *x; i++){
        for (int j = 0; j < *y; j++){
            //Living cells survive another evolution 
            //or Dead cells coming alive.
            int adj = adjacent_to(x, y, *grid, i, j);
            if(((adj==2 || adj==3) && (*(*(*grid+i)+j))==1)
                ||(adj==3 && (*(*(*grid+i)+j))!= 0)){
                tempGrid[i][j] = 1;
            }
            //Living cells to dead.
            else if ((adj<2 || adj>3) && (*(*(*grid+i)+j))==1){
                tempGrid[i][j] = -1;
            }
            else if((*(*(*grid+i)+j))== -1){
                tempGrid[i][j] = -1;
            }
            else{
                tempGrid[i][j] = 0;
            }
            
        }
    }
    for(int i = 0; i < *x; i++){
        for (int j = 0; j < *y; j++){
            (*(*(*grid+i)+j)) = tempGrid[i][j];
        }
    }
    freeMem(x, y, &tempGrid);
    return 0;
}