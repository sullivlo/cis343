//
// Created by Louis Sullivan and Brendan Nahed on 1/30/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "file_utilities.h"
#include "gameOfLife.h"


int read_file( char* filename, char **buffer ){
    //reference https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
    FILE* file1;
    file1 = fopen(filename, "r");

    //gets the size of the file
    int size;
    fseek(filename,0L, SEEK_END);
    size=ftell(filename);
    *buffer = malloc(size * sizeof(char));
    rewind(filename);
    fread(*buffer,size,1,filename);
    return size;
}


int write_file( char* filename, char *buffer, int size){
    //reference https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
    FILE* file2;
    file2 = fopen(filename, 'w');

    for (int k = size - 1; k >= 0; k--) {
        int* x = &buffer + k;
        fprintf(file2, "%s", x);
    }
    printf("%c", filename);
    return 0;


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
