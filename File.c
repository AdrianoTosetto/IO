#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include "File.h"

extern int errno;

string getString(){
    string buffer = NULL;
    
    unsigned int capacity = 0;

    unsigned int n = 0;
    int c;
    //reads characters from file until the end of file
    while ((c = fgetc(stdin)) != '\n'){
        if (n + 1 > capacity){
            if (capacity == 0){
                capacity = 32;
	}else if (capacity <= (UINT_MAX / 2)){
          capacity *= 2;
	}
        else{
        	free(buffer);
                return NULL;
        }

        string temp = (char *) realloc(buffer, capacity * sizeof(char));
        if (temp == NULL){
   		int err = errno;
	 	fprintf(stderr, "Error opening file: %s\n", strerror(err));
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        buffer[n++] = c;
    }

    if (n == 0 && c == EOF){
 	int err = errno;
   	fprintf(stderr, "Error: %s\n", strerror(err));
        return NULL;
     }

    string minimal = (char *)malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    minimal[n] = '\0';
    return minimal;
	
}


string readFile(const char *filename){
	FILE *file = fopen(filename,"r+");
	
    string buffer = NULL;
    
    unsigned int capacity = 0;

    unsigned int n = 0;
    int c;
    //reads characters from file until the end of file
    while ((c = fgetc(file)) && c != EOF){
        if (n + 1 > capacity){
            if (capacity == 0){
                capacity = 32;
	}else if (capacity <= (UINT_MAX / 2)){
                capacity *= 2;
	}else{
                free(buffer);
                return NULL;
        }

        string temp = (char *) realloc(buffer, capacity * sizeof(char));
        if (temp == NULL){
   		int err = errno;
	 	fprintf(stderr, "Error opening file: %s\n", strerror(err));
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        buffer[n++] = c;
    }

    if (n == 0 && c == EOF){
    	fclose(file);
 	int err = errno;
   	fprintf(stderr, "Error: %s\n", strerror(err));
        return NULL;
    }

    string minimal = (char *)malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    minimal[n] = '\0';

    fclose(file);
    return minimal;
}
void writeFile(const string fileName,bool overwrite,const char *format,...){
	FILE *file;
	va_list args;
	va_start(args,format);
	if(overwrite){
		file = fopen(fileName,"w+");
	}else{
		file = fopen(fileName,"a+");
	}
	if(file == NULL){
	    int err = errno;
   	    fprintf(stderr, "Error: %s\n", strerror(err));
   	    fclose(file);
   	    va_end(args);
   	    return ;
	}
	vfprintf(file,format,args);
	
	fclose(file);
	va_end(args);
}

void clsBuffer(){
	int value = getchar();
	
	while((value != '\n') && (value != EOF)) 
		value = getchar();
}

char** tokenizer(char *string,const char *delimiter){
	//this function divides a string and returns an array of tokens
	//for example, you need to divide a string like "my string" into
	//tokens, using character space as reference
	// char **tokens = tokenizer("my string"," ")
	//printf(tokens[0]) -> my
	//printf(tokens[1]  -> string
	char *token;
	char **tokens = (char **)malloc(strlen(string) * sizeof(char));
	int  tokensNumber = 0;
	
	char str[strlen(string)];
	strcpy(str,string);
	token = strtok(str,delimiter);

	
	while(token != NULL){
		*(tokens+tokensNumber) = (char *)malloc(sizeof(char)*(strlen(token) + 1));
	   	strcpy(*(tokens+tokensNumber),token);
	   	tokensNumber++;
		token = strtok(NULL,delimiter);
	}
	//tokens[tokensNumber] can be used instead *(tokens+tokensNumber) to access the elements

	*(tokens+tokensNumber) = NULL; //Flag to know where the array stops
	return tokens;
}
/*
* returns if a substring exists in a string
* text: 
*/
bool match(char *string,char *look_for){
	
	int i;
	int j;
	int auxtindex;

	char *auxt = (char *)calloc(sizeof(char),strlen(look_for));
	for(i = 0; i < strlen(string);i++){
		for(j = i,auxtindex = 0; j < strlen(look_for) + i;j++,auxtindex++){
			auxt[auxtindex] = string[j];
		}
		if(strcmp(look_for,auxt) == 0){
			free(auxt);
			return true;
		}
	}
	free(auxt);
	return false;
}


