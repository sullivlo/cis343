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
void drawGrid(int x, int y, int* grid[x][y]) {
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



    //printf("%d",xy);

    //char* world = atoi( argv[1]);

    fileSize = read_file(fileName, &buffer);
    // printf("%s\n", buffer);
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
    // for (int i = 0; i < x; i++) {
    //     for (int j = 0; j < y; j++) {
    //         printf("%d ", grid[i][j]);
    //     }
    //     printf("\n");


    // }
//     for(int i = 0; buffer[i] != ' '; i++) {
//         printf("Hi1\n");
//         if(i<2){
//             printf("Hi2\n");
//             x = strtok (&buffer[i],' ');
//             printf("Hi3\n");
//             printf("%s\n", x);
//             i++;
//         }
//         else if(i<5){
//             y = strtok (&buffer[i],' ');
//             printf("%s\n", y);
//             i++;
//         }
//         if(buffer[i]==' '){
//             i++;
//         }
//         if(buffer[i+1]=='\0'){
//             printf("%d\n", i);
//         }
//         if(i > 5){
//             return 0;
//         }

// }
    printf("\n");
    // x = buffer[0];
    // y = buffer[3];

    printf("x = %d \ny = %d\n", x , y);
    //write_file(world, buffer, filesize);

    //int grid[][];
    printf("\n");

    return 0;


}




