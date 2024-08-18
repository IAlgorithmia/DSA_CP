#include <stdio.h>
int main(){
    int i,j,n;
    printf("Enter the number of stars you want in your base :\n");
    scanf("%d", &n);
    for (i=1;i<=n;i++){
        for (j=1;j<=(n-i);j++){
            printf(" ");
        }
        if (i==1){
            printf("*");
        }
        else if (i!=n){
            printf("*");
            for (int k=1;k<=(2*(i-1)-1);k++){
                printf(" ");
            }
            printf("*");
        }
        else {
            for (int k=1;k<=2*n-1;k++){
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}