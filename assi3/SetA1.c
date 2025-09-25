#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>


char ss[40], tok1[10],tok2[10],tok3[10],tok4[10];
pid_t pid;
char ch[1],ch1[100];

void sep()
{
    strcpy(tok1,"\0");
    strcpy(tok2,"\0");
    strcpy(tok3,"\0");
    strcpy(tok4,"\0");

    sscanf(ss,"%s%s%s%s",tok1,tok2,tok3,tok4);
}

void count()
{
    int cc=0, wc=0, lc=0,j,fp;
    fp=open(tok3,O_RDONLY);
    if(fp== -1)
    printf("error");

    else
    {
        while (read(fp,ch,1)!=0)
        {
            printf("%c",ch[0]);
            if(ch[0]==' ' || ch[0]=='\n' || ch[0]=='\t')
            wc++;
            else
            cc++;

            if(ch[0]=='\n')
            lc++;
        }
        close(fp);
        if (strcmp(tok2,"c")==0)
    printf("\n total no of characters=%d\n",cc);
    
    else if(strcmp(tok2,"w")==0)
    printf("\n total no of words=%d\n",wc);

     else if(strcmp(tok2,"l")==0)
    printf("\n total no of lines=%d\n",lc);

    else if(strcmp(tok2,"cw")==0)
    printf("\n total no of character=%d & words=%d\n",cc,wc);

    else if(strcmp(tok2,"cl")==0)
    printf("\n total no of character=%d & lines=%d\n",cc,lc);

    else if(strcmp(tok2,"wl")==0)
    printf("\n total no of words=%d & lines=%d\n",wc,lc);

    else if(strcmp(tok2,"cwl")==0)
    printf("\n total no of character=%d & words=%d & lines=%d\n",cc,wc,lc);   
        
    }
}


int main()
{
    while (1)
    {
        printf("myshell$");
        gets(ss);
        sep();
        pid=fork();
        if(pid== 0)
        {
            if(strcmp(tok1,"count")==0)
            count(0);

            else if(strcmp(tok1,"exit")==0)
            exit(0);
            else
            printf("Bad Command");
        
        }
      
   else
        if(pid!=0)
        {
            waitpid(pid,NULL,0);
            printf("\n parent process competed\n\n");
            exit(0);
        }
    }
}


