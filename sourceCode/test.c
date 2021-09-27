#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

  int i = 0;

  pid_t pid;
  
  //for(i;i<5;i++){
  
  pid = fork();

  //}

  if(pid < 0){
    printf("error occured");
    return 1;
  } else if(pid == 0){

    // child process
    int i = 0;
    printf("Im the original child with pid number: %d\n\n",getpid());
    execlp("/home/looseleif/4061-Project1/outputInput", "/home/looseleif/4061-Project1/outputInput", NULL); // new program
    
  } else {

    while(wait(NULL)>0);
    
    printf("Child process finished\n");
    printf("I am parent process with pid: %d\n\n", getpid());
  }

  return 0;
}



  
