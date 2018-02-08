//

// Created by Louis Sullivan on 1/30/18.

//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef FILE_UTILITIES_H

#define FILE_UTILITIES_H

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

#endif
