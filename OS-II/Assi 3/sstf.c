#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[100], visited[100];
    int n, head, i, j;
    int total_seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++) {
        int min = 9999, index = -1;

        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(requests[j] - head);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        printf("Head moves from %d to %d with seek = %d\n", head, requests[index], min);

        total_seek += min;
        head = requests[index];
        visited[index] = 1;
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
