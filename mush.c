#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  char buffer[2048];
  char *tokenized_string;
  char *argument_list[sizeof(buffer)];
  printf("No, please, do go on: ");

  if (fgets(buffer, sizeof(buffer), stdin)!= NULL){
    buffer[strcspn(buffer, "\n")] = '\0';
    tokenized_string = strtok(buffer, " ,.");
    argument_list[0] = tokenized_string;
    int i = 0;

    while (tokenized_string != NULL )
    {
      argument_list[i] = strdup(tokenized_string);
      i++;
      tokenized_string = strtok(NULL, " ,.");
    }
    
    argument_list[i] = NULL;
    execvp(argument_list[0],argument_list);
  }





 }
  






