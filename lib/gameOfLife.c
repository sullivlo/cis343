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
    int** grid;
    char save;
    char quit;
    char resp;
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
    
    // //Creates the grid and populates the grid.
    
    printf("%s\n", buffer);
    tokenizer(&x, &y, &buffer, &grid);
    free(buffer);
    printf("%s\n", buffer);
    drawGrid(&x, &y, grid); 
    printf("Hit P to start.\n");
    scanf("%c", &save);
    resp = save;
    while(toupper(quit)!= 'Q'){  
        printf("%c\n", resp);
        printf("What is going on\n");
        //Drawing the grid.
        //Check to see if User wants to save before evolution.
        //If yes enters into process to write the file.
        if(toupper(resp)=='Q'){
            quit = 'Q';
        }
        else if(toupper(resp) == 'S'){
            char* newFile;
            printf("What would you like the file to be saved as?\n");
            scanf("%s", &newFile);
            newBuff(&x, &y, &buffer, grid);
            write_file(&newFile, buffer, fileSize);
            prompt(&save);
            resp = save;
        }
        else if(toupper(resp) == 'L'){
            char* loadFile;
            printf("What would you like the file to saved as?\n");
            scanf("%s", &loadFile);
            fileSize = read_file(loadFile, &buffer);
            freeMem(&x, &y, &grid);
            tokenizer(&x, &y, &buffer, &grid);
            free(buffer);
            // buffer_overRide(&x, &y, &fileSize, grid, &buffer);
            drawGrid(&x, &y, grid);
            prompt(&save);
            resp = save;

        }
        else if(toupper(resp) == 'P'){
            
            evolution(&x, &y, &grid);
            drawGrid(&x, &y, grid);
            prompt(&save);
            resp = save;
        }
        else{
            printf("Not a valid command. Try again.");
            prompt(&save);
            resp = save;
        }
        
    }
    freeMem(&x, &y, &grid);

    return 0;
}




