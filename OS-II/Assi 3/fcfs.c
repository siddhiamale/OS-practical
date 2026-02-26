#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[100], n, head, i;
    int total_seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++) {
        int diff = abs(requests[i] - head);
        printf("Head moves from %d to %d with seek = %d\n", head, requests[i], diff);

        total_seek += diff;
        head = requests[i];
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
