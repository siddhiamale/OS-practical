#include <stdio.h>
#include <string.h>

int bv[50];              
char fname[20][20];
int start[20], length[20];
int fileCount = 0;

int main() {
    int choice, i, j, flag;
    char name[20];
    int st, len;

    // Initialize bit vector with 0
    for (i = 0; i < 50; i++)
        bv[i] = 0;

    while (1) {
        printf("\n--- Sequential File Allocation ---\n");
        printf("1. Allocate File\n");
        printf("2. Show Directory\n");
        printf("3. Show Bit Vector\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:   // Allocate
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter start index (0–49): ");
            scanf("%d", &st);
            printf("Enter length: ");
            scanf("%d", &len);

            // Boundary check
            if (st < 0 || st + len > 50) {
                printf("Invalid start index or length!\n");
                break;
            }

            flag = 0;
            for (i = st; i < st + len; i++) {
                if (bv[i] == 1) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                for (i = st; i < st + len; i++)
                    bv[i] = 1;

                strcpy(fname[fileCount], name);
                start[fileCount] = st;
                length[fileCount] = len;
                fileCount++;

                printf("File allocated successfully.\n");
            } else {
                printf("Blocks already allocated!\n");
            }
            break;

        case 2:   // Directory
            printf("\nFile Name\tStart\tLength\n");
            for (i = 0; i < fileCount; i++) {
                if (fname[i][0] != '\0')
                    printf("%s\t\t%d\t%d\n",
                           fname[i], start[i], length[i]);
            }
            break;

        case 3:   // Bit vector
            printf("\nBit Vector (50 blocks):\n");
            for (i = 0; i < 50; i++)
                printf("%d ", bv[i]);
            printf("\n");
            break;

        case 4:   // Delete
            printf("Enter file name to delete: ");
            scanf("%s", name);

            for (i = 0; i < fileCount; i++) {
                if (strcmp(fname[i], name) == 0) {
                    for (j = start[i]; j < start[i] + length[i]; j++)
                        bv[j] = 0;

                    fname[i][0] = '\0';
                    printf("File deleted successfully.\n");
                    break;
                }
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}

