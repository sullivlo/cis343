// Author: Louis Sullivan, Brendan Nahed
//
//
//
#include "file_utilities.h"
#include "gameOfLife.h"

#include <stdio.h>


//allocae memory to the heap
int getMem(int** Mem)
{
//https://www.ics.uci.edu/~dan/class/165/notes/memory.html
}

//Display the grid to the termanal window
//drawGrid take a x, horizontal and a y, vertical to build a 2D grid
void drawGrid(int x, int y) {
    int grid[x][y];


    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            grid[i][j] = 0;
            printf("%2d", grid[i][j]);
        }
        printf("\n");


    }
}

// reference https://www.cprogramming.com/tutorial/lesson14.html
//Main will take 1 argument, of type string
//the file path to the grid txt file

int main(int argc,char* argv[])
{
    int counter;
    printf("Program Name Is: %s",argv[0]);

    if(argc==1)
	//User should only pass a file path to the cammand line
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name");

	printf("\nNumber Of Arguments Passed: %d",argc);

	printf("\nLooking for file " );
	
	printf( nargv[0]);
	
    //Should not need args more that 1
    if(argc>=2)
    {
        printf("\nNumber Of Arguments Passed: %d",argc);
        printf("\n----Following Are The Command Line Arguments Passed----");
        for(counter=0;counter<argc;counter++)
            printf("\nargv[%d]: %s",counter,argv[counter]);
	
	   
    }
    //Call fileUtility.c to read in the file path in th args
	
   //Cast string y vertices to int
   int x = atoi(args[1]);
   //Cast string y vertices to int
   int y = atoi( argv[2]);

   printf("\n");
   //printf("%d",xy);

   drawGrid(x,y);
   return 0;
    
	





}




