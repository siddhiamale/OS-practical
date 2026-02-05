#include <stdio.h>
#include <string.h>

int bv[50];              // Bit Vector
int link[50];            // Stores next block

char fname[20][20];
int start[20];           // Starting block of file
int fileCount = 0;

int n;

int main() {

    int choice, i, j, blocks, first, prev;
    char name[20];

    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    // Initialize
    for(i=0;i<n;i++){
        bv[i] = 0;
        link[i] = -1;
    }

    while(1){

        printf("\n--- Linked File Allocation ---\n");
        printf("1. Allocate File\n");
        printf("2. Show Directory\n");
        printf("3. Show Bit Vector\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){

        // ===== Allocate =====
        case 1:
            printf("Enter file name: ");
            scanf("%s",name);

            printf("Enter number of blocks required: ");
            scanf("%d",&blocks);

            first = -1;
            prev = -1;
            int count = 0;

            // Find free blocks
            for(i=0;i<n && count<blocks;i++){

                if(bv[i]==0){

                    bv[i] = 1;

                    if(first==-1)
                        first = i;

                    if(prev!=-1)
                        link[prev] = i;

                    prev = i;
                    link[i] = -1;

                    count++;
                }
            }

            if(count == blocks){
                strcpy(fname[fileCount],name);
                start[fileCount] = first;
                fileCount++;
                printf("File allocated successfully\n");
            }
            else
                printf("Not enough free blocks\n");

            break;

        // ===== Show Directory =====
        case 2:
            printf("\nFile Name\tBlocks\n");

            for(i=0;i<fileCount;i++){
                if(fname[i][0] != '\0'){

                    printf("%s\t\t",fname[i]);

                    int temp = start[i];
                    while(temp != -1){
                        printf("%d=>",temp);
                        temp = link[temp];
                    }
                    printf("NULL\n");
                }
            }
            break;

        // ===== Show Bit Vector =====
        case 3:
            printf("\nBit Vector:\n");
            for(i=0;i<n;i++)
                printf("%d ",bv[i]);
            printf("\n");
            break;

        // ===== Delete =====
        case 4:
            printf("Enter file name to delete: ");
            scanf("%s",name);

            for(i=0;i<fileCount;i++){
                if(strcmp(fname[i],name)==0){

                    int temp = start[i];

                    while(temp != -1){
                        int next = link[temp];
                        bv[temp] = 0;
                        link[temp] = -1;
                        temp = next;
                    }

                    fname[i][0] = '\0';
                    printf("File deleted\n");
                    break;
                }
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}

