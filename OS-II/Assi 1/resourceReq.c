#include <stdio.h>
#include <string.h>

int m,n,i,j,k;
int a[50][50], av[50], finish[50], max[50][50], need[50][50];
char s[200], str[20];

void get_data()
{
    printf("Enter no. of processes: ");
    scanf("%d",&n);

    printf("Enter no. of resources: ");
    scanf("%d",&m);

    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    printf("Enter MAX matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available resources:\n");
    for(i=0;i<m;i++)
        scanf("%d",&av[i]);

    for(i=0;i<n;i++)
        finish[i]=0;
}

void calc_need()
{
    printf("\nNeed matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-a[i][j];
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
}

int check_need(int p)
{
    for(j=0;j<m;j++)
        if(need[p][j] > av[j])
            return 1;
    return 0;
}

int main()
{
    int progress, safe=1;

    get_data();
    calc_need();

    strcpy(s,"");

    do
    {
        progress=0;

        for(i=0;i<n;i++)
        {
            if(!finish[i] && check_need(i)==0)
            {
                for(k=0;k<m;k++)
                    av[k]+=a[i][k];

                finish[i]=1;

                sprintf(str,"P%d ",i);
                strcat(s,str);

                progress=1;
            }
        }

    } while(progress);

    for(i=0;i<n;i++)
        if(finish[i]==0)
            safe=0;

    if(safe)
    {
        printf("\nSystem is in safe state");
        printf("\nSafe Sequence: %s\n",s);
    }
    else
        printf("\nSystem is NOT in safe state");

    return 0;
}
