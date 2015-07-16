#ifndef _FILE_H
#define _FILE_H
#endif
#include <stdio.h>
#include <stdlib.h>

typedef char* string;
typedef unsigned int uint;


/**
 * reads a file and returs it's content
 */
string readFile(const char* filename);

void writeFile(const string fileName,bool overwrite,const char *format,...);

//clear buffer

void clsBuffer();

string getString();
