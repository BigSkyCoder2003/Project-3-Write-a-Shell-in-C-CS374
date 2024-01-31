#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  while(1){
  char buffer[2048];
  char *tokenized_string;
  char *argument_list[128];
  printf("No, please, do go on: ");

  if (fgets(buffer, sizeof(buffer), stdin)!= NULL){
    buffer[strcspn(buffer, "\n")] = '\0';
    tokenized_string = strtok(buffer, " ,");
    argument_list[0] = tokenized_string;
    int i = 0;

    while (tokenized_string != NULL )
    {
      argument_list[i] = strdup(tokenized_string);
      i++;
      tokenized_string = strtok(NULL, " ,");
    }

    argument_list[i] = NULL;

    
if(strcmp(argument_list[0], "exit") == 0){
  exit(0);
  }
    else if(strcmp(argument_list[0], "cd") == 0){
      if(chdir(argument_list[1]) == -1){
      chdir(argument_list[1]);
      perror("chdir failed");
      }


      
    }  
    else{
    pid_t pid = fork();
    if (pid == 0){
    execvp(argument_list[0],argument_list);
    perror("execvp");
    exit(0);
    }
    else if (pid > 0){
      wait(NULL);
    }
    else{
      perror("fork failure");
      exit(1);
    }
    }
  }
  }





 }