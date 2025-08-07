#include<stdio.h>
#include<sys/types.h>
#include<unistd.h> 
#include<stdlib.h>      

void asort(int a[],int n);
void dsort(int a[],int n);

void main()
{
int n,i;
printf("Enter how many number\n");  // for size of array
scanf("%d",&n);
int *a = (int *)malloc(n * sizeof(int));  // Dynamic memory allocation

printf("\nEnter %d elements\n",n);
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
 pid_t pid = fork();  
 
 if(pid < 0)
 {
 printf("Failed to create child\n");
 exit(-1);
 }
 if (pid == 0)
 {
 int status;
 WIFEXITED(status);
 printf("Child Performing Sort by desceding order...\n");
 dsort(a,n);
printf("Child Sorted Array in descending order: \n ");
for(i = 0; i < n; i++)
	printf("%d ", a[i]);
printf("\n");
printf("\n...Child process completed...\n");
 
}
else
{
 wait(NULL);
printf("\nParent Process ID: %d\n", getpid());
printf("Parent Performing Sort by ascending order...\n");
asort(a,n);
printf("Child Sorted Array in ascending order: \n ");
for(i = 0; i < n; i++)
	printf("%d ", a[i]);
printf("\n");
printf("\n...Parent process completed...\n");
 }
}

void dsort(int a[],int n){
int i,j,temp;
for (int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if (a[j]>a[i]){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	}
	}
	}
}
void asort(int a[],int n){
int i,j,temp;
for (int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if (a[j]<a[i]){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	}
	}
	}
}

