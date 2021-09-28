#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main () {

  printf("I am the memory remapped child process of the parent process %d, and my new PID is %d\n\n", getppid(), getpid());
  return 0;
  
}
