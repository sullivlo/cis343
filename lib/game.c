// Author: Louis Sullivan, Brendan Nahed
//
//
//



//allocate memory to the heap
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gameOfLife.h"
#include "file_utilities.h"
#include "game.h"


// int getMem(int* x, int* y, int*** grid)
// {
// //https://www.ics.uci.edu/~dan/class/165/notes/memory.html
//     *grid = (int**) malloc((*x) * sizeof(int*));
//     for(int i =0 ; i < *y; ++i) {
//         *grid[i] = (int*) malloc((*y) * sizeof(int));
//     }
//     return 0;
// }


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

void newBuff(int* x, int *y, char** buffer, int** grid){
    printf("Made it1\n");
    for(int i = 0; i < *x; ++i){
        for(int j = 0; j < *y; ++j){
            *buffer = *(*(grid+i)+j) + '0';
            printf("i = %d, j = %d buffer = %s\n",i, j, *buffer);
        }
    }
    printf("Made it2\n");
    printf("%s\n", *buffer);
}

void freeMem(int* x, int* y, int*** grid){
    printf("%d\n", &grid);
  //free columns
    for(int i = (*y); i >= 0;--i){
        free((*grid)[i]);
        printf("i = %d\n", i);
        drawGrid(x, y, *grid);
    }
    // for(int i = (*y); i >= 0;--i){
    //     free((*grid)[i]);ß
    //     printf("i = %d\n", i);
    //     drawGrid(x, y, *grid);
    // }
 // free whole thing
 free ((*grid));
 printf("%d\n", &grid);
 drawGrid(x, y, *grid);
 
}

void getMem(int* x, int* y, int*** grid){
    *grid = (int**) malloc((*x) * sizeof(int*));
    for(int i =0 ; i < *y; ++i) {
        printf("%d", i);
        (*grid)[i] = (int*) malloc((*y) * sizeof(int));
    }
}

void tokenizer(int* x, int* y, char** buffer, int*** grid){
    *x = atoi(strtok(*buffer, " \n"));
    *y = atoi(strtok(NULL, " \n"));
    //Creates the grid and populates the grid.
    // Malloc the grid.
    // getMem(&x, &y, &grid);
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

int buffer_overRide(int* x, int* y, int* size, int** grid, char** buffer){    
    drawGrid(x , y, grid);
    printf("%s\n", *buffer);
    printf("%s\n", *(buffer+2));
    *buffer = malloc((*size) * sizeof(char));
    *buffer[0] = *(*(buffer + *x + ' ')); 
    *buffer[0] = *(*(buffer + *y + ' '+ '\n'));
    drawGrid(x , y, grid);
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
            // printf("grid[%d][%d] = %d\n", i, j, (*(*(*grid+i)+j)));
            // printf("tempGrid[%d][%d] = %d\n", i, j, tempGrid[i][j]);
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
