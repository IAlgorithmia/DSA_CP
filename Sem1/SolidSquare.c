#include <stdio.h>
int main(){
    int i,j,n;
    printf("Enter the number of stars you want in 1 side :\n");
    scanf("%d", &n);
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}