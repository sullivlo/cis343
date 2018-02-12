/**
* @Author: Louis Sullivan, Brendan Nahed
* @version 1.0
* @date Feb 11, 2018
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

#endif
