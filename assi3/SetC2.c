#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>


void search(char* tok2,char *fname,char* tok4)
{
char s[80],buffer[40];
int i=0,cnt=0,lc=1,fp;
fp=open(fname,O_RDONLY);
if(fp==-1)
{
printf("\n file not found");
return;
}
while(read(fp,buffer,1))
{
if(buffer[0]=='\n')
lc++;
if(buffer[0]=='\n' || buffer[0]=='\t' || buffer[0]==' ')
{
s[i]='\0';
i=0;
if(strstr(s,tok4))
{
if(strcmp(tok2,"f")==0)
{
printf("pattern \"%s\" found in \"%s\ at line no:%d\n",tok4,s,lc);
break;
}
if(strcmp(tok2,"c")==0)
{
cnt++;
}
if(strcmp(tok2,"a")==0)
{
printf("pattern \"%s\" found in \"%s\ at line no:%d\n",tok4,s,lc);

}
}
}
else
{
s[i]=buffer[0];
i++;
}
}//pattern
if(strcmp(tok2,"c")==0)
printf("\n total occurances=%d",cnt);
}



int main()
{
char ss[40], tok1[10],tok2[10],tok3[10],tok4[10];
int n;
while(1)
{
printf("\n myshell$");
fgets(ss,40,stdin);

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

case 3: if(fork()==0)
{
execlp(tok1,tok1,tok2,tok3,NULL);
}
wait(0);
break;

case 4:if(strcmp(tok1,"search")==0)
{
search(tok2,tok3,tok4);
}
else
{
 if(fork()==0)
{
execlp(tok1,tok1,tok2,tok3,tok4,NULL);
}
wait(0);
}
break;
}
}
}










