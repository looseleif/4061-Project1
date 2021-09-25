#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

  
  int pid = fork();

  if(pid < 0){
    printf("error occured");
    return 1;
  } else if(pid == 0){

    // child process
    printf("Im child with pid number: %d\n",getpid());
    execlp("/home/looseleif/4061-Project1/outputInput", "/home/looseleif/4061-Project1/outputInput", NULL); // new program

  } else {
    wait(NULL);
    printf("Child process finished\n");
    printf("I am parent process with pid: %d\n", getpid());
  }

  return 0;
}



  
