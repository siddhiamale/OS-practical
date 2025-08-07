#include<stdio.h>
#include<sys/types.h>
#include<unistd.h> 
void childProcess();
void parentProcess();

int main()
{
pid_t pid;
pid=fork();
if(pid == 0)
	childProcess();
else
	parentProcess();
return 0;
}

void childProcess()
{
printf("Child Id: %d\n",getpid());
printf("I am a child process\n");
}

void parentProcess()
{
printf("Parent Id: %d\n",getpid());
printf("I am a parent process\n");
}
