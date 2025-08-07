#include<stdio.h>
#include<sys/types.h>
#include<unistd.h> 
#include<stdlib.h>    

int main()
{
int pid=fork();
if(pid>0)
{
 printf("Parent process ");
 printf("ID = %d\n",getpid());
}
else if(pid == 0)
{
 printf("\nChild process");
 printf("ID = %d\n",getpid());
 printf("Parent ID= %d\n",getppid());
 sleep(5);
  printf("\nChild process");
 printf("ID = %d\n",getpid());
 printf("\nParent ID= %d\n",getppid());
}
else
{
printf("Failed to create child\n");
}
return 0;
}
