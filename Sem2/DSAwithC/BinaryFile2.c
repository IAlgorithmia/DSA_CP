#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char title[100];
    float price;
} Book;

int main()
{
    FILE *file;
    Book book;
    int bookCount = 0;
    float totalPrice = 0.0;
    float averagePrice;
    Book highestPriceBook;

    // Open the binary file in append mode
    file = fopen("books.bin", "ab");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Record book data
    printf("Enter book title (or 'q' to quit): ");
    scanf("%s", book.title);
    while (book.title[0] != 'q')
    {
        book.id = ++bookCount;

        printf("Enter book price: ");
        scanf("%f", &book.price);

        // Write the book data to the file
        fwrite(&book, sizeof(Book), 1, file);

        // Calculate total price
        totalPrice += book.price;
        printf("Enter book title (or 'q' to quit): ");
        scanf("%s", book.title);
    }

    // Close the file
    fclose(file);

    // Calculate average price
    averagePrice = totalPrice / bookCount;

    // Open the binary file in read mode
    file = fopen("books.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Find the book with the highest price
    highestPriceBook.price = 0;
    while (fread(&book, sizeof(Book), 1, file) == 1)
    {
        if (book.price > highestPriceBook.price)
        {
            highestPriceBook = book;
        }
    }

    // Display average cost and book with the highest price
    printf("\nAverage cost of the books: %.2f\n", averagePrice);
    printf("Book with highest price:\n");
    printf("ID: %d\n", highestPriceBook.id);
    printf("Title: %s\n", highestPriceBook.title);
    printf("Price: %.2f\n", highestPriceBook.price);

    // Seek to the record just before the book with the maximum price
    fseek(file, -2 * sizeof(Book), SEEK_CUR);
    fread(&book, sizeof(Book), 1, file);
    printf("\nRecord just before the book with the maximum price:\n");
    printf("ID: %d\n", book.id);
    printf("Title: %s\n", book.title);
    printf("Price: %.2f\n", book.price);

    // Seek to the record just after the book with the maximum price
    fseek(file, sizeof(Book), SEEK_CUR);
    fread(&book, sizeof(Book), 1, file);
    printf("\nRecord just after the book with the maximum price:\n");
    printf("ID: %d\n", book.id);
    printf("Title: %s\n", book.title);
    printf("Price: %.2f\n", book.price);

    // Seek to the last record of the file
    fseek(file, -sizeof(Book), SEEK_END);
    fread(&book, sizeof(Book), 1, file);
    printf("\nLast record of the file:\n");
    printf("ID: %d\n", book.id);
    printf("Title: %s\n", book.title);
    printf("Price: %.2f\n", book.price);

    // Close the file
    fclose(file);

    return 0;
}
