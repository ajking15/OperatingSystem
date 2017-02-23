//Homework 1
//Simple_shell
//Name: Abhinav Jambulingam 
//Email: abhj1@umbc.edu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Starting buffer size to be 1k bites
//Can be mallocted later for further iteration
#define BUFFERSIZE 1024
#define ARGUMENT " \t\r\n"

int main(int argc, char *argv[])  
{
  char *command;
  char buffLine[BUFFERSIZE];
  int exit = 1;
  do
  {
    printf("$_Please enter a command: ");
	gets(buffLine);
   
   //seperates the buffer line by the argument
    if ((command = strtok(buffLine, ARGUMENT))) 
	{
      
	  //the cd command
      if (strcmp(command, "cd") == 0) 
	  {
        char *cmd = strtok(0, ARGUMENT);

        if (!cmd) fprintf(stderr, "cd needs destination.\n"); //When no destination is specified. 
        else chdir(cmd);

      }
	  else if (strcmp(command, "exit") == 0) //when exit is typed
	  {
        exit = 0;

      } 
	  else system(buffLine); //Sends the inputed comand line to system. 

      
    }
  }
	while(exit == 1); //when exit is type the loop will exit
  

  return 0;
}