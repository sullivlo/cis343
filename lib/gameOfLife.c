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
            printf("%d ", grid[i][j]);
        }
        printf("\n");

    }
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

    fileSize = read_file(fileName, &buffer);
    int count = 0;
    x = atoi(strtok(buffer, " \n"));
    y = atoi(strtok(NULL, " \n"));
    int grid[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            grid[i][j] = atoi(strtok(NULL, " \n"));
        }
    }
    drawGrid(x, y, grid);

    printf("Would you like to save this file: Y/N\n");
    scanf("%c", &save);
    if(save == 'Y'){
        char* newFile;
        printf("What would you like the file to be saved as?\n");
        scanf("%s", &newFile);
        write_file(newFile, buffer, filesize);
        // realloc(newFile, 0);
    }
    printf("\n");
    

    printf("x = %d \ny = %d\n", x , y);
    //write_file(world, buffer, filesize);

    printf("\n");

    return 0;


}




