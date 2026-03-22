#include <stdio.h>

int main() {
    int requests[100], n, head, i;
    int max = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);

        // find max request
        if(requests[i] > max) {
            max = requests[i];
        }
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

  
    int total_seek = head + max;

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
