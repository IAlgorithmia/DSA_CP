#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char name[100];
    printf("Enter the name of the file you want : ");
    gets(name);
    FILE *fpout;
    int n;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    fflush(stdin); //Read and ignore the enter pressed after n
    fpout = fopen(name, "wt");
    if (fpout == NULL)
    {
        printf("fopen failed!");
        exit(1);
    }
    int i;
    fprintf(fpout, "%d ", n);
    printf("Enter the data : \n");
    int inpval;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &inpval);
        fprintf(fpout, "%d ", inpval);
    }
    fclose(fpout);
    FILE *fpin;
    fpin = fopen(name, "rt");
    if (fpin == NULL)
    {
        printf("Fopen failed");
        exit(1);
    }
    int total, readval, sum = 0;
    fscanf(fpin, "%d", &total);
    printf("The total number of values are %d and the values are : \n", total);
    for (i = 0; i < n; i++)
    {
        fscanf(fpin, "%d", &readval);
        printf("%d\n", readval);
        sum = sum + readval;
    }
    printf("Their sum is %d and their average is %.2f\n", sum, (sum/((float)total)));
}