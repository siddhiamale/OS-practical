#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

    sort(requests, n);

    int pos;
    for(i = 0; i < n; i++) {
        if(head < requests[i]) {
            pos = i;
            break;
        }
    }

    // Move right
    for(i = pos; i < n; i++) {
        int diff = abs(requests[i] - head);
        printf("Head moves from %d to %d with seek = %d\n", head, requests[i], diff);

        total_seek += diff;
        head = requests[i];
    }

    // Move left
    for(i = pos - 1; i >= 0; i--) {
        int diff = abs(requests[i] - head);
        printf("Head moves from %d to %d with seek = %d\n", head, requests[i], diff);

        total_seek += diff;
        head = requests[i];
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
