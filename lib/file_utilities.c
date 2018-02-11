//
// Created by Louis Sullivan and Brendan Nahed on 1/30/18.
//
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include "gameOfLife.h"
#include "file_utilities.h"
#include "game.h"

//read file takes a (char*) filename specified by the user in gameOfLife.c
//The **buffer is empty the first call
//When called again buffer will pass the char array of the grid

int read_file( char* filename, char **buffer ){

    //reference https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-
    // that-to-another-file

    FILE* file1 = fopen(filename, "r");
    //gets the size of the file
    if(file1 == NULL){
        printf("No File Found.\n");
        return -1;
    }
    int size;

    fseek(file1,0L, SEEK_END);
    size=ftell(file1);
    *buffer = malloc(size * sizeof(char));
    rewind(file1);
    fread(*buffer,size,1,file1);
    return size;
}

//File name is specified by the user in gameOfLife.c 
//Buffer is the char array taken from the users txt file
//size is from the users txt file when write file was called
int write_file( char* filename, char *buffer, int size){
    //reference https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
    printf("%s\n", buffer);
    FILE* file2;
    file2 = fopen(filename, "w");

    // char * x =  (buffer + 0);
    fprintf(file2, "%s ", buffer);
    printf("%s", filename);

    return 0;

}

