#include<stdio.h>

int main(){
    int i, j;
    for(i = 1; i<=8; i=i+1){
        if(i%2!=0){
            for(j = 1; j<=8; j= j+1){
                printf("* ");

            }
            printf("\n");
        }
        else{
        
            for(j = 1; j<=8; j= j+1){
                printf(" *");
            }
            printf("\n");
        }
    }
    return 0;
}