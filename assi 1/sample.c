#include<stdio.h>
#include<stdlib.h>      // For malloc()
#include<unistd.h>      // For fork(), getpid()
#include<sys/wait.h>    // For wait()

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));  // Dynamic memory allocation

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid_t pid = fork();  // Create a child process

    if(pid == 0)  // Child Process
    {
        printf("\n[Child] Process ID: %d\n", getpid());
        printf("[Child] Performing Insertion Sort...\n");
        insertionSort(arr, n);

        printf("[Child] Sorted Array (Insertion Sort): ");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else if(pid > 0)  // Parent Process
    {
        wait(NULL);  // Parent waits for child to complete
        printf("\n[Parent] Process ID: %d\n", getpid());
        printf("[Parent] Performing Bubble Sort...\n");
        bubbleSort(arr, n);

        printf("[Parent] Sorted Array (Bubble Sort): ");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        printf("Fork failed!\n");
        return 1;
    }

    free(arr);  // Free dynamically allocated memory
    return 0;
}

// -----------------------------
// Bubble Sort Implementation
// -----------------------------
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// -----------------------------
// Insertion Sort Implementation
// -----------------------------
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

