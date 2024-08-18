#include <stdio.h>

int main() {
    FILE *fpin, *fout;
    char ch;

    // Open the input file in read mode
    fpin = fopen("input.txt", "r");
    if (fpin == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file in write mode
    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error creating output file.\n");
        fclose(fpin);
        return 1;
    }

    // Read from the input file character by character until EOF is encountered
    while ((ch = fgetc(fpin)) != EOF) {
        // Write the character to the output file
        fputc(ch, fout);
    }

    // Close the files
    fclose(fpin);
    fclose(fout);

    printf("File copied successfully.\n");

    return 0;
}
