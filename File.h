#ifndef _FILE_H
#define _FILE_H
#endif




typedef char* string;


/**
 * reads a file and returs it's content
 */

string readFile(const char* filename);
/*
* 
*/


void writeFile(const char* filename,bool overwrite,const char *format,...);
