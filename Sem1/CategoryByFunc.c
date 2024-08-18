#include <stdio.h>
int knowcat(int perc){
	if (perc>=60)
		printf("You belong to category 1");
	else if (perc>=50)
	    printf("You belong to category 2");
	else if (perc>=40)
		printf("You belong to category 3");
	else
		printf("You haven't passed");
}
int main(){
	float arr[6];
	printf("Enter the marks in subject 1\n");scanf("%f", &arr[0]);
	printf("Enter the marks in subject 2\n");scanf("%f", &arr[1]);
	printf("Enter the marks in subject 3\n");scanf("%f", &arr[2]);
	printf("Enter the marks in subject 4\n");scanf("%f", &arr[3]);
	printf("Enter the marks in subject 5\n");scanf("%f", &arr[4]);
	arr[5] = (arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5.0;
	printf("Based on your marks, ");
	knowcat(arr[5]);
}
