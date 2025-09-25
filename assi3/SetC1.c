#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>


int toks(char *s,char *tok[])
{
int i=0;
char *p;
p=strtok(s," ");
while(p!=NULL)
{
 tok[i++]=p;
p=strtok(NULL," ");
}
tok[i]=NULL;
return i;
}
void typeline(char *op,char *fn)
{
int fp,i,j,n;
char c;
fp=open(fn, O_RDONLY);
if(fp==-1)
{
printf("file %s not found\n",fn);
return;
}
if(strcmp(op,"a")==0)
{
while(read(fp,&c,1)>0)
printf("%c",c);
close(fp);
return;
}

n=atoi(op);
if(n>0)
{
i=0;
while(read(fp,&c,1)>0)
{
printf("%c",c);
if(c=='\n')
i++;
if(i==n)
break;
}
}

if(n<0)
{
i=0;
while(read(fp,&c,1)>0)
{
if(c=='\n')
i++;
}
lseek(fp,0,SEEK_SET);
j=0;
while(read(fp,&c,1)>0)
{
if(c=='\n')
j++;
if(j==i+n+1)
break;
}
while(read(fp,&c,1)>0)
{
printf("%c",c);
}
}
close(fp);
}


int main()
{
char buff[80], *args[10];
while(1)
{
printf("\n myshell$");
fgets(buff,80,stdin);
buff[strlen(buff)-1]='\0';
int n=toks(buff,args);
switch(n)
{
case 1:
if(strcmp(args[0],"exit")==0)
exit(1);
if(!fork())
execlp(args[0],args[0],NULL);
break;

case 2:
if(!fork())
execlp(args[0],args[0],args[1],NULL);
break;

case 3:
if(strcmp(args[0],"typeline")==0)
typeline(args[1],args[2]);
else
{
if(!fork())
execlp(args[0],args[0],args[1],args[2],NULL);
}
break;

case 4:
if(!fork())
execlp(args[0],args[0],args[1],args[2],args[3],NULL);
break;
}
}
return 0;
}
