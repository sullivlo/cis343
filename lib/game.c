/**
* @Author: Louis Sullivan, Brendan Nahed
* @version 1.0
* @date Feb 11, 2018
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "gameOfLife.h"
#include "file_utilities.h"
#include "game.h"




//Display the grid to the termanal window
//drawGrid take a x, horizontal and a y, vertical to build a 2D grid
/* Print the grid array to the termanal window
*  @param pointer to a horizontal (x), veritcal (y) and values of the grid array
*  @return void
*/
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


/**
* newBuff creates a buffer charactor array using the grid int array
* @param int (x), int (y), point to a pointer of a grid and buffer 
* sources: https://www.geeksforgeeks.org/snprintf-c-library/
* @return void
*/
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


/** 
* freeMem deallocates the memory of the 2d array, grid
* @param: pointer to a x,y value. Pointer to a pointer, grid.
* @return void
*/
void freeMem(int* x, int* y, int*** grid){
  //free columns
    for(int i = (*y); i >= 0;--i){
        free((*grid)[i]);
    }
    
 free ((*grid));
}

/** 
* getMem allocates of the 2d array
* @param: pointer to a x,y value. Pointer to a pointer, grid.
* @return void
*/
void getMem(int* x, int* y, int*** grid){
    *grid = (int**) malloc((*x) * sizeof(int*));
    for(int i =0 ; i < *y; ++i) {
        (*grid)[i] = (int*) malloc((*y) * sizeof(int));
    }
}

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

void prompt(char* response){
    *response = ' ';
    printf("\n");
    printf("Would you like to save this file: S\n");
    printf("Would you like to load a file: L\n");
    printf("Would you like to quit the game?: Q\n");
    printf("Or to continue playing. P\n");
    scanf("%s", response);
}


//Looks for the Adjacent living blocks.
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

//Evolves the grid and creates a temperary grid. 
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

