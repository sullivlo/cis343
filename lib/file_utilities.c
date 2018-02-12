/**
* @Author: Louis Sullivan, Brendan Nahed
* @version 1.0
* @date Feb 11, 2018
*/
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include "gameOfLife.h"
#include "file_utilities.h"
#include "game.h"


/**
* read_file
* @parm char* filename - takes in a pointer to
* the file that the user wants to read in.
* @parm char **buffer- is the buffer that is written to from filename.
* @return size - size is the size of the read in file.
* Source: https://stackoverflow.com/questions/42033932/
* c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
*/
int read_file( char* filename, char **buffer ){
    FILE* file1 = fopen(filename, "r");
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
    fclose(file1);
    return size;
}


/**
* write_file
* @parm char* filename - takes in a pointer to
* the file that the user wants to write to.
* @parm char **buffer- is a pointer to a char array
* that is written to a new file called filename.
* @return 0 - to end the method.
* Source: https://stackoverflow.com/questions/42033932/
* c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
*/
int write_file( char* filename, char *buffer, int size){
    FILE* file2;
    file2 = fopen(filename, "w");
    fputs(buffer, file2);
    fclose(file2);
    return 0;

}

