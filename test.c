#include <stdio.h>
#include "File.h"

int main(int argc, char** argv){
  
  const char *filename = "myfile.txt";
  string txt = readFile(filename);
  printf(txt); //prints the content of myfile.txt
  
  
  return 0;
}
