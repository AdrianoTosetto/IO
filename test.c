#include <stdio.h>
#include <string.h>
#include "File.h"


using namespace std;



int main(int argc, char* argv[]){
	
	//Test for getString and readFile
	printf("Put the name of the file: \n");
	string fileName = getString();     //reads an input from the keyboard(stdin)
	printf(readFile(fileName)); //gets the content of fileName
	
	
	//Test for tokenizer
	printf("Put a string to split: \n");
	string str = getString();
	printf("Put the delimiter: \n");
	string delimiter = getString();
	char **tokens = tokenizer(str,delimiter);
	
	for(int i = 0; tokens[i] != NULL;i++){
		printf("Tokens number %d: %s\n",i+1,tokens[i]);
	}
	
	//test for match
	
	
	printf("Put the string: \n");
		string str = getString();
		printf("Put the substring: \n");
		string substr = getString();
		if(match(str,substr)){
			printf("Substring: %s exists in main string: %s\n",substr,str);
		}else{
			printf("Substring: %s does not exists in main string: %s\n",substr,str);
		}
	
    return 0;       
}
