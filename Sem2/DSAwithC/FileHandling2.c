#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* fpin;
    int count, i;
    int c_digit = 0, c_alpha = 0, c_space = 0, c_sym = 0;
    char ch, dummych, filename[50];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    fflush(stdin);

    fpin = fopen(filename, "r");
    if (fpin == NULL) {
        printf("File opening error.\n");
        return 1;
    }
    else {
        fscanf(fpin, "%d", &count);
        fscanf(fpin, "%c", &dummych); // read and ignore the separating char blank or new line

        for (i = 1; i <= count; i++) {
            fscanf(fpin, "%c", &ch);

            if (ch == ' ') {
                c_space++;
            }
            else if (isdigit(ch)) {
                c_digit++;
            }
            else if (isalpha(ch)) {
                c_alpha++;
            }
            else {
                c_sym++;
            }
        }

        fclose(fpin);

        printf("Count of: digits: %d, alphabets: %d, symbols: %d, spaces: %d\n",
               c_digit, c_alpha, c_sym, c_space);
    }

    return 0;
}
