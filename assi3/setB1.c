#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>


void list(char* tok2,char* tok3)
{
int cnt=0;
DIR *dp;
struct dirent *de;
dp=opendir(tok3);
if(dp==NULL)
{
printf("\n%s directory not found",tok3);
}
else
{
if(strcmp(tok2,"n")==0)
{
while(1)
{
de=readdir(dp);
if(de==NULL)
break;
cnt++;
}
printf("\n total files:%d",cnt);
}
if(strcmp(tok2,"f")==0)
{
while(1)
{
de=readdir(dp);
if(de==NULL)
break;
printf("\n files name:%s",de->d_name);
}
}
if(strcmp(tok2,"i")==0)
{
while(1)
{
de=readdir(dp);
if(de==NULL)
break;
printf("\n files name:%s",de->d_name);
printf("\n inode no:%ld",de->d_ino);
}
}
}
}


int main()
{
char ss[40], tok1[10],tok2[10],tok3[10],tok4[10];
int n;
while(1)
{
printf("\n myshell$");
gets(ss);

n=sscanf(ss,"%s%s%s%s",tok1,tok2,tok3,tok4);
switch(n)
{
case 1: if(fork()==0)
{
execlp(tok1,tok1,NULL);
}
wait(0);
break;


case 2: if(fork()==0)
{
execlp(tok1,tok1,tok2,NULL);
}
wait(0);
break;

case 3: if(strcmp(tok1,"list")==0)
{
list(tok2,tok3);
}
else
{
if(fork()==0)
{
execlp(tok1,tok1,tok2,tok3,NULL);
}
wait(0);
}
break;

case 4: if(fork()==0)
{
execlp(tok1,tok1,tok2,tok3,tok4,NULL);
}
wait(0);
break;
}
}
}










