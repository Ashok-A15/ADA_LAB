#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void linearSearch(int* arr,int key, int n){
	for(int i=0; i<n; i++){
		count++;
		if (arr[i]==key) return;
	}
}


void main(){
	int n,i,key;
	int* arr;
	
	srand(time(0));
	FILE *b,*w,*a;
	system("rm b.txt w.txt a.txt");
	
	b = fopen("b.txt","a");
	w = fopen("w.txt","a");
	a = fopen("a.txt","a");
	
	for(n=10;n<1000;n+=10){
		arr = (int*)malloc(n*sizeof(int));
		
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		
		//Best Case
		count=0;
		key=arr[0];
		linearSearch(arr,key,n);
		fprintf(b,"%d\t%d\n",n,count);
		
		//Worst Case
		count=0;
		key = arr[n-1] = 9999;
		linearSearch(arr,key,n);
		fprintf(w,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		key = arr[n/2] = 9999;
		linearSearch(arr,key,n);
		fprintf(a,"%d\t%d\n",n,count);
	}
	
	fclose(b); fclose(w); fclose(a);
}
