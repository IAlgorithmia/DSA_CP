#include <stdio.h>
int comp(int a, int b, int c){
	if (a>b){
		if (a>c){
			return a;
		}
		else {
			return c;
		}
	}
	if (b>a){
		if (b>c){
			return b;
		}
		else {
			return c;
		}
	}
}
int main(){
	printf("Enter the first number : \n");int a;scanf("%d", &a);
	printf("Enter the second number : \n");int b;scanf("%d", &b);
	printf("Enter the third number : \n");int c;scanf("%d", &c);
	printf("The maximum of these numbers is %d", comp(a,b,c));
}
