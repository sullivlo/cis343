//
// Created by Louis Sullivan on 1/30/18.
//


#include "file_utilities.h"
#include "gameOfLife.h"


int read_file( char* filename, char **buffer ){
    //reference https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
    FILE* file1;
    file1 = fopen(filename, "r");

    //gets the size of the file
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    buffer = malloc(size);
    read(file1, &buffer, 1);
    return size;


    //
    *buffer = malloc(size);


    return 0;
}


int write_file( char* filename, char *buffer, int size){
    //reference https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
    FILE* file2;
    file2 = fopen(filename, 'w');

    for (int k = size - 1; k >= 0; k--) {
        int* x = &buffer + k;
        fprintf(file2, "%s", x);
    }
    printf(filename, '\O');
    return 1;


    return 0;
}