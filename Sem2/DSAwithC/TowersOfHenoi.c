#include <stdio.h>
void toh(int N, char S, char AUX, char D)
{
    if (N == 1)
    {
        printf("Disk %d from %c to %c\n", N, S, D);
    }
    else
    {
        toh(N-1, S, D, AUX);
        printf("Disk %d from %c to %c\n", N, S, D);
    }
}
int main()
{
    printf("How many disks do you want to be there ? \n");
    int num; scanf("%d", &num);
    toh(num, 'A', 'B', 'C');
    return 0;
}