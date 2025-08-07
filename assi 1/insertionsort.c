#include<stdio.h>
int insertionSort(int a[],int n);
void main()
{
int a[10],n=5;
printf("Enter %d array elements\n",n);
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Array elements are\n");
for(int i=0;i<n;i++)
{
printf(" %d",a[i]);
}
insertionSort(a,n);
printf("\nSorted array elements are\n");
for(int i=0;i<n;i++)
{
printf(" %d",a[i]);
}
printf("\n");
}

int insertionSort(int a[],int n)
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
