#include <stdio.h>
int main(){
	printf("Enter whether you want to convert frmo Binary to decimal(1) or decimal to binary(2) : \n");
	int choice;
	scanf("%d", &choice);
	if (choice == 1){
		int input;
		printf("Enter the number in binary : \n");
		scanf("%d", &input);
		int j = 1;
		int ans = 0;
		while (input != 0){
			ans = ans + j*(input%10);
			j=j*2;
			input = input / 10;
		}
		printf("The number in decimal is %d", ans);
	}
	else if(choice == 2){
		int input;
		printf("Enter the number in decimal : \n");
		scanf("%d", &input);
		int i = 0;
		int dup = input;
		while(dup != 0){
			i++;
			dup = dup / 2;
		}
		int arr[i];
		int j;
		for (j=0;j<=i-1;j++){
			arr[j] = input % 2;
			input = input /2;
		}
		for (j=i-1;j>=0;j--){
			printf("%d", arr[j]);
		}
		}
	}
