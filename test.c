#include <stdio.h>
#include <string.h>
#include "File.h"


using namespace std;



int main(int argc, char* argv[]){
	
	char **tokens = tokenizer(readFile("teste.txt")," ");
	int i;
	for(i = 0; tokens[i] != NULL;i++){
		printf("%s\n",tokens[i]);
	}
	
	/**
	* tokens[i] == NULL tells where the tokens array finishes 
	* it outputs : my
	* 			   string
	* 			   I
	* 			   want
	* 			   to 
	* 			   divide
 	*/
	
	
    return 0;       
}
