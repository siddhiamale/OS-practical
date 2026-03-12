#include <stdio.h>
#include <string.h>

int n, m;
int all[50][50], max[50][50], need[50][50];
int avl[15], finish[50];
char seq[100], temp[10];

void get_data()
{
    int i, j;

    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Enter no of resources: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &all[i][j]);

    printf("Enter max matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avl[i]);

    for (i = 0; i < n; i++)
        finish[i] = 0;
}

void cal_need()
{
    int i, j;

    printf("Need Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - all[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int can_execute(int i)
{
    int j;

    for (j = 0; j < m; j++)
    {
        if (need[i][j] > avl[j])
            return 0;
    }

    return 1;
}

int safe_state()
{
    int i, j, done = 0;

    seq[0] = '\0';

    while (done < n)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (!finish[i] && can_execute(i))
            {
                for (j = 0; j < m; j++)
                    avl[j] += all[i][j];

                finish[i] = 1;
                done++;
                found = 1;

                sprintf(temp, "P%d ", i);
                strcat(seq, temp);

                printf("%s\n", seq);
            }
        }

        if (!found)
            return 0;
    }

    return 1;
}

int main()
{
    get_data();
    cal_need();

    if (safe_state())
    {
        printf("System is in a safe state\n");
    }
    else
    {
        printf("System is NOT in a safe state\n");
    }

    return 0;
}
