#include <stdio.h>
int main(){
    int n, i, j;
    printf("Enter the number of stars you want in 1 side :\n");
    scanf("%d", &n);
    for (i=1;i<=n;i++){
        printf("* ");
    }
    printf("\n");
    for (i=1;i<=(n-2);i++){
        for (j=1;j<=n;j++){
            if (j==1 || j==n){
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (i=1;i<=n;i++){
        printf("* ");
    }
    return 0;
}