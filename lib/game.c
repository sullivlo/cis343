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


// int getMem(int* x, int* y, int** mem)
// {
// //https://www.ics.uci.edu/~dan/class/165/notes/memory.html
//     mem = (int**) malloc((*x) * sizeof(int*));
//     mem[0] = (int*) malloc((*y) * (*x) *sizeof(int));
//     for(int i = 0; i < *y; i++){
//         mem[i] = (*mem + (*y) * i);
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

void freeMem(int *x, int *y, int*** grid){
  //free columns
  printf("Hi1\n");
    printf("Hi2\n");
    free(*grid);
    printf("Hi3\n");
 // free whole thing
  printf("Hi4\n");
  printf("%p\n", **grid);
  drawGrid(x, y, *grid);
 free (**grid);
 printf("Hi5\n");
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
    tempGrid[0] = (int*) malloc((*y) * (*x) *sizeof(int));
    for(int i = 0; i < *y; i++){
        tempGrid[i] = (*tempGrid + (*y) * i);
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
            else{
                tempGrid[i][j] = 0;
            }
            // printf("grid[%d][%d] = %d\n", i, j, (*(*(*grid+i)+j)));
            // printf("tempGrid[%d][%d] = %d\n", i, j, tempGrid[i][j]);
        }
    }
    drawGrid(x, y, tempGrid);
    for(int i = 0; i < *x; i++){
        for (int j = 0; j < *y; j++){
            (*(*(*grid+i)+j)) = tempGrid[i][j];
        }
    }
    freeMem(x,y, &tempGrid);
    return 0;
}
