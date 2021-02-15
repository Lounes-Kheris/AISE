#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>

#define MAX 100
int main(void){
  int descr[2];
  char msgLire[MAX], msgEcrire[MAX];

  pid_t pid = fork();

  if(pid == 0){
    close(descr[1]);
    read(descr[0], msgLire, MAX);
    printf("C'est le processus fils(pid =%d) : %s\n", getpid(), msgLire);
  }else{
    close(descr[0]);
    sprintf(msgEcrire, "hi soon !");
    write(descr[1], msgEcrire, MAX);
    printf("C'est le processus pére (pid = %d) : %s\n", getpid(), msgEcrire);
    wait(NULL);
  }

  return 0;
  
}
