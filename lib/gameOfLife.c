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


int getMem(int** Mem)
{
//https://www.ics.uci.edu/~dan/class/165/notes/memory.html
    return 0;
}


//Display the grid to the termanal window
//drawGrid take a x, horizontal and a y, vertical to build a 2D grid
void drawGrid(int x, int y, int grid[][y]) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if(grid[i][j]!= -1)
                printf("%d ", grid[i][j]);
            else
                printf("- ");
        }
        printf("\n");
    }
 printf("\n");
}

int adjacent_to (int x, int y, int grid[][y], int i, int j) {
    //Count keeps track of the adjacent living cells.
    int count = 0;
    //Checks around the Cell
    for (int k=i-1; k<=i+1; k++) {
        for (int l=j-1; l<=j+1; l++){
            if((-1<k && -1<l) && (x>k && y>l)){
                printf("grid[%d][%d] = %d count for position = %d.\n", k, l, grid[k][l], count);
                if(grid[k][l]==1){
                   count++;
                }
                 
            }
        }
    }
    if(grid[i][j]==1){
        count--;
    }
    printf("grid[%d][%d] = %d count for position = %d.\n", i, j, grid[i][j], count);
    return count;
}

int evolution(int x, int y, int grid[][y]){
    int tempGrid[x][y];
    for(int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            //Living cells survive another evolution.
            if((adjacent_to(x, y, grid, i, j)==2 || adjacent_to(x, y, grid, i, j)==3)&& grid[i][j]==1){
                    tempGrid[i][j] = 1;
            }
            //Living cells to dead.
            else if ((adjacent_to(x, y, grid, i, j)<2 || adjacent_to(x,y, grid, i, j)>3) && grid[i][j]==1){
                tempGrid[i][j] = -1;
            }
            else if((adjacent_to(x,y, grid, i, j)==3 && grid[i][j]== -1)){
                tempGrid[i][j] = 1;
            }
            else{
                tempGrid[i][j] = 0;
            }

        }
    }
    drawGrid(x, y, tempGrid);
    return tempGrid;
}


// reference https://www.cprogramming.com/tutorial/lesson14.html
//Main will take 1 argument, of type string
//the file path to the grid txt file

int main(int argc,char* argv[])
{
    int fileSize;
    int x;
    int y;
    int i = 0; 
    char* fileName;
    char* buffer;
    char save;
    printf("Program Name Is: %s",argv[0]);
    if(argc==1)
    {
        //User should only pass a file path to the cammand line
        printf("No Extra Command Line Argument Passed Other Than Program Name\n");
        printf("Number Of Arguments Passed: %d\n",argc);
        printf("Looking for file \n" );
        printf( "%s", argv[0]);
        return 0;
    }

    //Should not need args more that 1
    if(argc>=2)
    {
        printf("Number Of Arguments Passed: %d\n",argc);
        printf("----Following Are The Command Line Arguments Passed----\n");
        printf("argv[%d]: %s\n", 1, argv[1]);
        fileName = argv[1];
    }
    //Call fileUtility.c to read in the file path in the args

    //Tokenizing the Buffer File.
    fileSize = read_file(fileName, &buffer);
    x = atoi(strtok(buffer, " \n"));
    y = atoi(strtok(NULL, " \n"));
    //Creates the grid and populates the grid.
    int grid[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            grid[i][j] = atoi(strtok(NULL, " \n"));
        }
    }    
    //Drawing the grid.
    drawGrid(x, y, grid);
    //Check to see if User wants to save before evolution.
    printf("Would you like to save this file: Y/N\n");
    scanf("%c", &save);
    //If yes enters into process to write the file.
    if(save == 'Y'){
        char* newFile;
        printf("What would you like the file to be saved as?\n");
        scanf("%s", &newFile);
        write_file(newFile, &buffer, fileSize);
        // realloc(newFile, 0);
    }
    grid[x][y] = evolution(x, y, grid);
    // adjacent_to(x, y, grid, 1, 1);
    drawGrid(x, y, grid);
    printf("\n");
    

    printf("x = %d \ny = %d\n", x , y);
    //write_file(world, buffer, filesize);

    printf("\n");

    return 0;


}




