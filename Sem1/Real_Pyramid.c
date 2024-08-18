#include<stdio.h>

int main(){
    int i, j, k;
    for (i = 1; i<= 5; i=i+1){
        for(j=5;j>i;j=j-1){
            printf(" ");
        }
        for(k=1; k<=2*i-1; k=k+1){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}