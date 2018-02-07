//
// Created by Louis Sullivan and Brendan Nahed on 1/30/18.
//
#include <stdio.h>

int read_file(char* filename, char **buffer ){
    FILE* f;
    int size;
    f = fopen(filename, "r");
    if(!f){
        printf("File not found.");
        return 0; 
    }
    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    *buffer = (char*) malloc(size);
    fread(*buffer, size, 1, filename);
    fclose(filename);
    return size;
}

int write_file(char* filename, char *buffer, int size){
    FILE* f;
    f = fopen(filename, "w");
}