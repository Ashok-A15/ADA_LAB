
#include <stdio.h>

void main(){
	int m,n,rem, count=0;;
	printf("Enter m and n>> ");
	scanf("%d %d",&m,&n);
	
	while(n!=0){
		count++;
		rem=m%n;
		m=n;
		n=rem;
	}
	
	printf("GCD: %d\nCount: %d\n",m, count);
}
