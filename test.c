#include <stdio.h>
#include "File.h"

int main(int argc, char** argv){
  //example for readFile
  const char *filename = "myfile.txt";
  string txt = readFile(filename);
  printf(txt); //prints the content of myfile.txt
  
  
  //example for tokenizer
  char **tokens = tokenizer("my string I want to divide"," ");
	int i;
	for(i = 0; i < 6;i++){
		printf("%s\n",tokens[i]);
	}
		/**
	* it outputs : my
	* 			   string
	* 			   I
	* 			   want
	* 			   to 
	* 			   divide
 	*/
  
  return 0;
}
