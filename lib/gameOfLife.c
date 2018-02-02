// Author: Louis Sullivan
//
//
//
#include "file_utilities.h"
#include "gameOfLife.h"

#include <stdio.h>



int getMem(int** Mem)
{
//https://www.ics.uci.edu/~dan/class/165/notes/memory.html
}

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
int main(int argc,char* argv[])
{
    int counter;
    printf("Program Name Is: %s",argv[0]);

    if(argc==1)
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
  
   
        printf("\nNumber Of Arguments Passed: %d",argc);

	printf("\nLooking for file " );
	
	printf( nargv[0]);

	



/*    int x = atoi( argv[1]);

    int y = atoi( argv[2]);

    int xy = x*y;
    printf("\n");
    //printf("%d",xy);

    drawGrid(x,y);
    return 0;
*/

}




