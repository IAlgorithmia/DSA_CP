#include <stdio.h>

int main()
{
    FILE *fpin, *fpout;
    int ch;

    // Open the input file in read mode
    fpin = fopen("input.txt", "r");
    if (fpin == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file in write mode
    fpout = fopen("output.txt", "w");
    if (fpout == NULL)
    {
        printf("Error creating output file.\n");
        fclose(fpin);
        return 1;
    }
    int status;
    // Read character by character from the input file until the end
    while (!feof(fpin))
    {
        status = fscan(fpin, "%c", &ch);
        if (status != EOF)
        {
            fprintf(fpout, "%c", ch);
        }
    }

    // Close the files
    fclose(fpin);
    fclose(fpout);

    printf("File copied successfully.\n");

    return 0;
}
