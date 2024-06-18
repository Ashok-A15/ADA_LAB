#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linearSearch(int *a, int k, int n) {
 for (int i = 0; i < n; i++) {
 if (*(a + i) == k) {
 return i;
 }
 }
 return -1;
}
int binarySearch(int key, int *a, int high, int low) {
 if (low <= high) {
 int mid = low + (high - low) / 2; // To avoid potential overflow
 if (*(a + mid) == key)
 return mid;
 else if (*(a + mid) > key)
 return binarySearch(key, a, mid - 1, low);
 else
 return binarySearch(key, a, high, mid + 1);
 }
 return -1;
}
int main() {
 int arr[100];
 int n, key, r;
 for (;;) {
 printf("ENTER 1. TO LINEAR SEARCH\n2. TO BINARY SEARCH\n3. 
TO EXIT\n");
 int ch;
 scanf("%d", &ch);
 switch (ch) {
 case 1:
 printf("ENTER THE NUMBER OF ELEMENTS\n");
 scanf("%d", &n);
 printf("ENTER THE ELEMENTS OF THE ARRAY\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("ENTER THE KEY ELEMENT\n");
 scanf("%d", &key);
 r = linearSearch(arr, key, n);
 if (r != -1) {
 printf("The element is present at the index %d\n", r);
 } else {
 printf("Element not found\n");
 }
 break;
 case 2:
 printf("ENTER THE NUMBER OF ELEMENTS\n");
 scanf("%d", &n);
 printf("ENTER THE ELEMENTS OF THE ARRAY\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("ENTER THE KEY ELEMENT\n");
 scanf("%d", &key);
 r = binarySearch(key, arr, n - 1, 0);
 if (r != -1) {
 printf("The element is present at the index %d\n", r);
 } else {
 printf("Element not found\n");
 }
 break;
 default:
 exit(0);
 }
 }
 return 0;
}













PLOTTER CODE;
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void merge(int *arr,int beg,int mid,int end)
{
 int i,j,k;
 int n1=(mid-beg)+1;
 int n2=end-mid;
 int left[n1],right[n2];
 for(i=0;i<n1;i++)
 left[i]=arr[beg+i];
 for(j=0;j<n2;j++)
 right[j]=arr[mid+j+1];
 i=0;j=0;k=beg;
 while(i<n1&&j<n2)
 {
 count++;
 if(left[i]<=right[j])
 arr[k]=left[i++];
 else
 arr[k]=right[j++];
 k++;
 }
 while(i<n1)
 arr[k++]=left[i++];
 while(j<n2)
 arr[k++]=right[j++];
}
void mergesort(int *arr,int beg,int end)
{
 if(beg<end)
 {
 int mid=(beg+end)/2;
 mergesort(arr,beg,mid);
 mergesort(arr,mid+1,end);
 merge(arr,beg,mid,end);
 }
}
void worst(int arr[],int beg,int end)
{
 if(beg<end)
 {
 int mid=(beg+end)/2;
 int i,j,k;
 int n1=(mid-beg)+1;
 int n2=end-mid;
 int a[n1],b[n2];
 for(i=0;i<n1;i++)
 a[i]=arr[(2*i)];
 for(j=0;j<n2;j++)
 b[j]=arr[(2*j)+1];
 
 worst(a,beg,mid);
 worst(b,mid+1,end);
 
 for(i=0;i<n1;i++)
 arr[i]=a[i];
 for(j=0;j<n2;j++)
 arr[j+i]=b[j];
 }
}
void main()
{
 int *arr,n;
 srand(time(NULL));
 FILE *f1,*f2,*f3,*f4;
 f1=fopen("MERGESORTBEST.txt","a");
 f2=fopen("MERGESORTWORST.txt","a");
 f3=fopen("MERGESORTAVG.txt","a");
 f4=fopen("WORSTDATA.txt","a");
 for(n=2;n<=1024;n=n*2)
 {
 arr=(int *)malloc(sizeof(int)*n);
 for(int i=0;i<n;i++)
 *(arr+i)=i+1;
 count=0;
 //Best case
 mergesort(arr,0,n-1);
 fprintf(f1,"%d\t%d\n",n,count);
 //worst case
 count=0;
 worst(arr,0,n-1);
 for(int i=0;i<n;i++)
 fprintf(f4,"%d ",*(arr+i));
 fprintf(f4,"\n");
 mergesort(arr,0,n-1);
 fprintf(f2,"%d\t%d\n",n,count);
 //AVG case
 for(int i=0;i<n;i++)
 *(arr+i)=rand()%n;
 count=0;
 mergesort(arr,0,n-1);
 fprintf(f3,"%d\t%d\n",n,count);
 free(arr);
 }
 fclose(f1);
 fclose(f2);
 fclose(f3);
 fclose(f4);
 printf("DATA IS ENTERED IN TO FILE\n");
}

