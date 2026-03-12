#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[100], n, head, i, j, temp;
    int total_seek = 0;
    int disk_size = 199;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter request sequence:\n");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    // sort requests
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(req[i] > req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    int index;

    for(i=0;i<n;i++)
        if(req[i] >= head)
        {
            index = i;
            break;
        }

    // move LEFT
    for(i=index-1;i>=0;i--)
    {
        int diff = abs(req[i] - head);
        printf("Head moves from %d to %d with seek = %d\n", head, req[i], diff);
        total_seek += diff;
        head = req[i];
    }

    // go to 0
    int diff = abs(head - 0);
    printf("Head moves from %d to 0 with seek = %d\n", head, diff);
    total_seek += diff;
    head = 0;

    // jump to end of disk
    printf("Head moves from 0 to %d with seek = %d\n", disk_size, disk_size);
    total_seek += disk_size;
    head = disk_size;

    // service remaining requests
    for(i=n-1;i>=index;i--)
    {
        diff = abs(req[i] - head);
        printf("Head moves from %d to %d with seek = %d\n", head, req[i], diff);
        total_seek += diff;
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek/n);

    return 0;
}
