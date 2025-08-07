#include<stdio.h>
#include<sys/types.h>
#include<unistd.h> 
int main()
{
pid_t pid=fork();
char *args[]={"/home/bcs/Downloads/OS Practical",NULL};
if(pid == 0)
	execv(args[0],args);
else
	printf("I am parent\n");
	
return 0;
}
