// Author: Louis Sullivan, Brendan Nahed
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

//free the buffer and the game board
void freeMem(int *x, int *y, int*** grid){
    printf("%d\n", &grid);
  //free columns
    for(int i = (*y); i < 10;++i){
        printf("i = %d\n holds: %d", i, (*grid)[i]);
        free((*grid)[i]);
    
}
 // free starting pointer
 free ((*grid));
 printf("%d\n", &grid);
 drawGrid(x, y, *grid);
 
}

//ask user to continue playing, save, load, or quit the game
//accepts a pointer charactor, saves the users responce 
void prompt(char* response){
    *response = ' ';
    printf("\n");
    printf("Would you like to save this file: S\n");
    printf("Would you like to load a file: L\n");
    printf("Would you like to quit the game?: Q\n");
    printf("Or to continue playing. P\n");
    scanf("%s", response);
}

//accepts the prevous buffer then creates a new buffer on the heap

int buffer_overRide(int* x, int* y, int* size, int** grid, char** buffer){    
    drawGrid(x , y, grid);
    printf("%s\n", *buffer);
    printf("%s\n", *(buffer+2));
    *buffer = malloc((*size) * sizeof(char));
    *buffer[0] = *(*(buffer + *x + ' ')); 
    *buffer[0] = *(*(buffer + *y + ' '+ '\n'));
    //drawGrid(x , y, grid);
    printf("Hi4\n");
    for(int i = 1; i < (*x)+1; ++i){
        for(int j = 0; j < *y; ++j){
            printf("Hi3\n");
            *buffer[i] = *(*(buffer + ' '+ *(*(grid+(i-1))+j)));
            printf("%d\n", *(*(grid+(i-1))+j));
        }
        *buffer[i] = *(*(buffer + ' '+ '\n'));
        printf("Hi5\n");
    }
    return 0;
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
int evolution(int* x, int* y, int*** grid,int** tempGrid){
    tempGrid = (int**) malloc((*x) * sizeof(int*));
    for(int i =0 ; i < *y; ++i) {
        tempGrid[i] = (int*) malloc((*y) * sizeof(int));
    }
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
             printf("grid[%d][%d] = %d\n", i, j, (*(*(*grid+i)+j)));
            // printf("tempGrid[%d][%d] = %d\n", i, j, tempGrid[i][j]);
        }
    }
    for(int i = 0; i < *x; i++){
        for (int j = 0; j < *y; j++){
            (*(*(*grid+i)+j)) = tempGrid[i][j];
        }
    }
    printf("%s\n", "in evolution");
    freeMem(x, y, &tempGrid);
    return 0;
}
