/**
* @Author: Louis Sullivan, Brendan Nahed
* @version 1.0
* @date Feb 11, 2018
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "gameOfLife.h"
#include "file_utilities.h"
#include "game.h"
/**
* main
* int argc - the size of argv[]
* char* argv[] - a char array of command line arguments.
* return: 0 - to end the method.
* Main runs the game of life. It allows the user to
* Play, Save, Load, and Quit.
*/
int main(int argc,char* argv[])
{
    int fileSize;
    int x;
    int y;
    int i = 0; 
    char* fileName;
    char* buffer;
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
    //Creates the grid and populates the grid.
    int** grid;
    tokenizer(&x, &y, &buffer, &grid);
    free(buffer);
    drawGrid(&x, &y, grid); 
    printf("Hit P to start.\n");
    scanf("%c", &save);
    resp = save;
    //Game will quit if the user enters the letter q.
    while(toupper(quit)!= 'Q'){  
        //Drawing the grid.
        //Check to see if User wants to save before evolution.
        //If yes enters into process to write the file.
        if(toupper(resp)=='Q'){
            quit = 'Q';
        }
        //User can specify a file to save their current game.
        else if(toupper(resp) == 'S'){
            char* newFile;
            printf("What would you like the file to be saved as?\n");
            scanf("%s", &newFile);
            newBuff(&x, &y,fileSize, &buffer, grid);
            write_file(&newFile, buffer, fileSize);
            free(buffer);
			char input;
            prompt(&input);
            resp = input;
        }
        //User can load a game by entering the letter l.
        else if(toupper(resp) == 'L'){
            char* loadFile;
            printf("What is the file you would like to load?\n");
            scanf("%s", &loadFile);
            fileSize = read_file(&loadFile, &buffer);
            freeMem(&x, &y, grid);
            tokenizer(&x, &y, &buffer, &grid);
            free(buffer);
            drawGrid(&x, &y, grid);
            char input;
            prompt(&input);
            resp = input;


        }
        //User can interact to the next elevation by entering the letter p.
        else if(toupper(resp) == 'P'){
            evolution(&x, &y, &grid);
            drawGrid(&x, &y, grid);
            char input;
            prompt(&input);
            resp = input;
        }
        //User has not entered a correct letter, please try again.
        else{
            printf("Not a valid command. Try again.");
            char input;
            prompt(&input);
            resp = input;
        }
    }
    freeMem(&x, &y, grid);
    return 0;
}



