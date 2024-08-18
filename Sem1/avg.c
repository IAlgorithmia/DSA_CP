#include<stdio.h>
main(){
	int i,s,a;
	for(i=1;i<=5;i=i+1){
	printf("enter the %d no \n",i);
	scanf("%d",&a);
	s=s+a;
	
	}
	printf("the average is %d",s/5);
}
