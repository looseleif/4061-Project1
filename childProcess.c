#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main () {

  printf("I am the child process of %d, and my PID is %d\n", getppid(), getpid());
  return 0;
  
}
