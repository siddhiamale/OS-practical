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

    int temp_head = head;

    
    // 🔹 Move LEFT (print remaining)
    for(i = pos - 1; i >= 0; i--) {
        printf("Head moves from %d to %d with seek = %d\n",
               temp_head, requests[i], abs(requests[i] - temp_head));
        temp_head = requests[i];
    }

// 🔹 Move RIGHT (print all)
    for(i = pos; i < n; i++) {
        printf("Head moves from %d to %d with seek = %d\n",
               temp_head, requests[i], abs(requests[i] - temp_head));
        temp_head = requests[i];
    }


    // 🔥 IMPORTANT: Simplified total
    int max = requests[n - 1];
    int total_seek = head + max;

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
