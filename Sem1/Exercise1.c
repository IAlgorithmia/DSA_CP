#include <stdio.h>
// write the multiplication table of a number
int main(){
    float a;
    int i=1;
    // By desi method 
    printf("Enter the number of which you want the table: ");
    scanf("%f", &a);
    printf("%.1f X 1 = %.1f\n", a,a*1);
    printf("%.1f X 2 = %.1f\n", a,a*2);
    printf("%.1f X 3 = %.1f\n", a,a*3);
    printf("%.1f X 4 = %.1f\n", a,a*4);
    printf("%.1f X 5 = %.1f\n", a,a*5);
    printf("%.1f X 6 = %.1f\n", a,a*6);
    printf("%.1f X 7 = %.1f\n", a,a*7);
    printf("%.1f X 8 = %.1f\n", a,a*8);
    printf("%.1f X 9 = %.1f\n", a,a*9);
    printf("%.1f X 10 = %.1f\n", a,a*10);
    // By loop method 
    do
    {
        printf("%.1f X %d = %.1f \n", a, i, a*i);
        i = i + 1;
    } while (i<=10);
        
    return 0;
}
