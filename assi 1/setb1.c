#include<stdio.h>
#include<sys/types.h>
#include<unistd.h> 
#include<stdlib.h>      // For malloc()

void isort(int a[],int n);
void bsort(int a[],int n);

int main()
{
int n,i;
printf("Enter how many number\n");  // for size of array
scanf("%d",&n);
int *a = (int *)malloc(n * sizeof(int));  // Dynamic memory allocation

printf("\nEnter %d elements\n",n);
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
 pid_t pid = fork();  // to Create a child process
 if(pid == 0)  // Child Process
    {
        printf("\nChild Process ID: %d\n", getpid());
        printf("Child Performing Insertion Sort...\n");
        isort(a, n);  // performs insertion sort on child process

        printf("Child Sorted Array Insertion Sort: ");
        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else if(pid > 0)  // Parent Process
    {
        sleep(5);  
        printf("\nParent Process ID: %d\n", getpid());
        printf("Parent Performing Bubble Sort...\n");
        bsort(a, n);  // performs bubble sort on parent process

        printf("Parent Sorted Array Bubble Sort : ");
        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else
    {
        printf("Failed to create fork\n");
        return 1;
    }
    free(a);  // to Free dynamically allocated memory
    return 0;
}

void isort(int a[],int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
key=a[i];
for(j=i-1;j>=0 && (key<a[j]);j--)
{
a[j+1]=a[j];
}
a[j+1]=key;
}
}

void bsort(int a[],int n)
{
int i,j,temp;
for(i=0;i<n;i++){
for(j=0;j<n-i-1;j++){
if(a[j]>a[j+1]){
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}

