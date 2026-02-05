#include <stdio.h>

int bv[50];              // Bit vector
int idxBlock[50][20];    // Blocks attached to index
int count[50];           // Number of blocks attached
int n;

int main()
{
    int ch,i,j,idx,blocks,b;

    printf("Enter number of disk blocks: ");
    scanf("%d",&n);

    // Initialize
    for(i=0;i<n;i++)
    {
        bv[i]=0;
        count[i]=0;
    }

    while(1)
    {
        printf("\n1.Allocate\n2.Show Directory\n3.Show Bit Vector\n4.Delete\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {

        // ===== Allocate =====
        case 1:
            printf("Enter index block: ");
            scanf("%d",&idx);

            if(bv[idx]==1)
            {
                printf("Index already used\n");
                break;
            }

            bv[idx]=1;

            printf("Enter number of blocks: ");
            scanf("%d",&blocks);

            count[idx]=blocks;

            for(i=0;i<blocks;i++)
            {
                printf("Enter block: ");
                scanf("%d",&b);

                if(bv[b]==0)
                {
                    bv[b]=1;
                    idxBlock[idx][i]=b;
                }
                else
                {
                    printf("Block already allocated\n");
                    i--;
                }
            }
            break;


        // ===== Show Directory =====
        case 2:
            for(i=0;i<n;i++)
            {
                if(bv[i]==1 && count[i]>0)
                {
                    for(j=0;j<count[i];j++)
                    {
                        printf("%d -> %d\n",i,idxBlock[i][j]);
                    }
                }
            }
            break;


        // ===== Show Bit Vector =====
        case 3:
            for(i=0;i<n;i++)
                printf("%d ",bv[i]);
            printf("\n");
            break;


        // ===== Delete =====
        case 4:
            printf("Enter index block to delete: ");
            scanf("%d",&idx);

            if(bv[idx]==1)
            {
                bv[idx]=0;

                for(i=0;i<count[idx];i++)
                    bv[idxBlock[idx][i]]=0;

                count[idx]=0;
                printf("Deleted\n");
            }
            else
                printf("Index not found\n");

            break;

        case 5:
            return 0;
        }
    }
}

