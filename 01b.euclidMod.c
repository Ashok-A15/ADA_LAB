



#include <stdio.h>
void main(){
	int m,n, count=0;;
	printf("Enter m and n>> ");
	scanf("%d %d",&m,&n);
	
	while(n>0){
		count++;
		if (m>n)
			m=m-n;
		else
			n=n-m;
	}
	
	printf("GCD: %d\nCount: %d\n",m, count);
}
