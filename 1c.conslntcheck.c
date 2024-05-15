
#include <stdio.h>

void main(){
	int m,n,min,count=0;;
	printf("Enter m and n>> ");
	scanf("%d %d",&m,&n);
	
	min = (m>n) ? n : m;
	
	while(min>0){
		count++;
		if (m%min==0 && n%min==0)
			break;
		min--;
	}
	
	printf("GCD: %d\nCount: %d\n",m, count);
}
