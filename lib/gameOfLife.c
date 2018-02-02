// Author: Louis Sullivan
//
//
//
#include <stdio.h>



int getMem(int** Mem)
{
//https://www.ics.uci.edu/~dan/class/165/notes/memory.html
}

void drawGrid(int grid[][]) {

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            grid[i][j] = 0;
            printf("%2d", grid[i][j]);
        }
        printf("\n");


    }
}

int loadGrid(char* f){

return 0;
}


// reference https://www.cprogramming.com/tutorial/lesson14.html
int main(int argc,char* argv[])
{
    int counter;
    printf("Program Name Is: %s",argv[0]);

    if(argc==1)
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name");

    if(argc>=2)
    {
        printf("\nNumber Of Arguments Passed: %d",argc);
        printf("\n----Following Are The Command Line Arguments Passed----");
        for(counter=0;counter<argc;counter++)
            printf("\nargv[%d]: %s",counter,argv[counter]);
    }


    char* world = atoi( argv[1]);

    int grid[][] = loadGrid(world);
    int xy = x*y;
    printf("\n");
    //printf("%d",xy);

    drawGrid(grid[][]);
    return 0;


}




