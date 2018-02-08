//
// Created by Louis Sullivan and Brendan Nahed on 1/30/18.
//
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include "gameOfLife.h"
#include "file_utilities.h"

int read_file( char* filename, char **buffer ){
    //reference https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
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


int write_file( char* filename, char *buffer, int size){
    //reference https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
    FILE* file2;
    file2 = fopen(filename, "w");

    for (int k = size - 1; k >= 0; k--) {
        char* x =  *(&buffer + k);
        fprintf(file2, "%s", x);
    }

    printf("%s", filename);
    return 1;


    return 0;

//int read_file(char* filename, char **buffer ){
//    FILE* f;
//    int size;
//    f = fopen(filename, "r");
//    if(!f){
//        printf("File not found.");
//        return 0;
//    }
//    fseek(f, 0L, SEEK_END);
//    size = ftell(f);
//    *buffer = (char*) malloc(size);
//    fread(*buffer, size, 1, filename);
//    fclose(filename);
//    return size;
//}

//int write_file(char* filename, char *buffer, int size){
//   FILE* f;
//   f = fopen(filename, "w");
}
