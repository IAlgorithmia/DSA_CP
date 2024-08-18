#include <stdio.h>
struct spterm
{
    int row;
    int col;
    int val;
};
void transpose(struct spterm origterms[], struct spterm transterms[], int nz)
{
	int i, foreach[nz];
    for (i = 0; i < nz; i++)
    {
        foreach[i] = 0;
    }
    for (i = 1; i <= nz; i++)
    {
        foreach[origterms[i].col]++;
    }
    int startingarray[nz];
    startingarray[0] = 1;
    for (i = 1; i < nz; i++)
    {
        startingarray[i] = startingarray[i - 1] + foreach[i - 1];
        
    }
    int index;
    for (i = 1; i <= nz; i++)
    {
        index = startingarray[origterms[i].col];
        if (index != 0)
        {
            transterms[index].row = origterms[i].col;
            transterms[index].col = origterms[i].row;
            transterms[index].val = origterms[i].val;
        }
        startingarray[origterms[i].col]++;
    }
}
int main()
{
    int i, j, rows, columns;
    printf("Enter the desired number of rows of the array : \n");
    scanf("%d", &rows);
    printf("Enter the desired number of columns of the array : \n");
    scanf("%d", &columns);
    int nz, value;
    nz = 0;
    struct spterm origterms[100];
    struct spterm transterms[100];
    origterms[0].row = rows;
    origterms[0].col = columns;
    transterms[0].row = columns;
    transterms[0].col = rows;
    for (i = 0; i <= rows - 1; i++)
    {
        for (j = 0; j <= columns - 1; j++)
        {
            printf("Enter the element at index [%d,%d] for the Matrix\n", i, j);
            scanf("%d", &value);
            if (value != 0)
            {
                nz++;
            	origterms[nz].val = value;
                origterms[nz].row = i;
                origterms[nz].col = j;
			}
        }
    }
    origterms[0].val = nz;
    transterms[0].val = nz;
    printf("The original matrix is : \n");
    int k;
    k = 1;
    for (i = 0; i <= rows - 1; i++)
    {
        for (j = 0; j <= columns - 1; j++)
        {
            if (origterms[k].row == i && origterms[k].col == j)
            {
                printf("%2d ", origterms[k].val);
                k++;
            }
            else
            {
                printf("%2d ", 0);
            }
        }
        printf("\n");
    }
    transpose(origterms, transterms, nz);
	printf("The resultant matrix is : \n");
    k = 1;
    for (i = 0; i < columns; i++)
    {
    	for (j = 0; j < rows; j++)
    	{
    		if (transterms[k].row == i && transterms[k].col == j)
            {
                printf("%2d ", transterms[k].val);
                k++;
            }
            else
            {
                printf("%2d ", 0);
            }
		}
		printf("\n");
	}
}