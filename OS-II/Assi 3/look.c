#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[100], n, head, i, j, temp;
    int total_seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort the requests
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(requests[i] > requests[j]) {
                temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    int index;

    // Find position of head
    for(i = 0; i < n; i++) {
        if(requests[i] > head) {
            index = i;
            break;
        }
    }

    // Move LEFT first
    for(i = index-1; i >= 0; i--) {
        int diff = abs(requests[i] - head);
        printf("Head moves from %d to %d with seek = %d\n", head, requests[i], diff);
        total_seek += diff;
        head = requests[i];
    }

    // Then move RIGHT
    for(i = index; i < n; i++) {
        int diff = abs(requests[i] - head);
        printf("Head moves from %d to %d with seek = %d\n", head, requests[i], diff);
        total_seek += diff;
        head = requests[i];
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
