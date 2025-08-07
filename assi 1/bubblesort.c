#include<stdio.h>
void bubblesort(int a[],int n);
void display(int a[],int n);
void main(){
int a[10],i,n;
printf("Enter size :-");
scanf("%d",&n);
printf("Enter elements :-");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
bubblesort(a,n);
display(a,n);
}
void bubblesort(int a[],int n){
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
void display(int a[],int n){
for(int i=0;i<n;i++){
printf(" %d",a[i]);
}
}
