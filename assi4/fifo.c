#include<stdio.h>
int prs[20],frm[10]={0};
int m[50][50];
int tp,tf,totpf=0,currp=0,currf=0;
int i,j,pf;
int chkpgfault()
{
for(i=0;i<tf;i++)
{
if(frm[i] == prs[currp])
{
break;
}
}
if(i == tf)
{
return -1;
}
else
{
return i;
}
}
void display()
{
for(i=0;i<tf;i++)
{
m[currp][i]=frm[i];
		
}
}
void main()
{
printf("how many page reference string:");
scanf("%d",&tp);
printf("Enter page reference string:\n");
for(i=0;i<tp;i++)
{
scanf("%d",&prs[i]);
}
printf("How many frames:");
scanf("%d",&tf);
while(currp<tp)
{
pf=chkpgfault();
if(pf == -1)
{
totpf++;
frm[currf]=prs[currp];
currf++;
if(currf == tf)
currf=0;
}
display();
currp++;
}
printf("\n frames\n");
for(i=0;i<tf;i++)
{
for(j=0;j<tp;j++)
{
printf("%d",m[j][i]);
}
printf("\n");
}
printf("\n total page fault is:%d\n",totpf);
}

