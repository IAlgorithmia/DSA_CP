#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    float marks;
};

void generate_binary_file(const char *file_path)
{
    FILE *fpout = fopen(file_path, "wb");
    if (fpout == NULL)
    {
        printf("Error opening file for writing.");
        return;
    }

    struct Student student;
    while (1)
    {
        printf("Enter the student name (-1 to stop): ");
        fgets(student.name, sizeof(student.name), stdin);

        if (student.name[0] == '-' && student.name[1] == '1')
            break;

        printf("Enter the student marks: ");
        scanf("%f", &student.marks);
        fflush(stdin); // Consume the newline character

        fwrite(&student, sizeof(struct Student), 1, fpout);
    }

    fclose(fpout);
}

float calculate_average(const char *file_path)
{
    float total_marks = 0.0;
    int num_students = 0;

    FILE *fpin = fopen(file_path, "rb");
    if (fpin == NULL)
    {
        printf("Error opening file for reading.");
        return 0.0;
    }

    struct Student student;
    while (fread(&student, sizeof(struct Student), 1, fpin))
    {
        total_marks += student.marks;
        num_students++;
    }

    fclose(fpin);

    if (num_students > 0)
    {
        float average = total_marks / num_students;
        return average;
    }
    else
    {
        return 0.0;
    }
}

int main()
{
    const char *file_path = "student_records.bin";

    // Generate the binary file
    generate_binary_file(file_path);

    // Read from the binary file and calculate the average
    float average_marks = calculate_average(file_path);

    printf("The average marks of the students is: %.2f\n", average_marks);

    return 0;
}