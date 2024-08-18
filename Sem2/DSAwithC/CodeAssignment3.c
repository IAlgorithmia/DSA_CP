#include <stdio.h>
#include <stdlib.h>

// Structure to represent a sparse matrix element
struct SparseElement {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    int numElements;
    struct SparseElement *elements;
};

// Function to multiply two sparse matrices
struct SparseMatrix multiplySparseMatrices(struct SparseMatrix matrix1, struct SparseMatrix matrix2) {
    if (matrix1.cols != matrix2.rows) {
        printf("Error: Matrix dimensions mismatch.\n");
        exit(1);
    }

    struct SparseMatrix result;
    result.rows = matrix1.rows;
    result.cols = matrix2.cols;
    result.numElements = 0;
    result.elements = NULL;

    // Creating a temporary matrix for easier multiplication
    int **tempMatrix = (int **)malloc(matrix1.rows * sizeof(int *));
    for (int i = 0; i < matrix1.rows; i++) {
        tempMatrix[i] = (int *)calloc(matrix2.cols, sizeof(int));
    }

    // Calculating the temporary matrix
    for (int i = 0; i < matrix1.numElements; i++) {
        for (int j = 0; j < matrix2.numElements; j++) {
            if (matrix1.elements[i].col == matrix2.elements[j].row) {
                tempMatrix[matrix1.elements[i].row][matrix2.elements[j].col] += 
                    matrix1.elements[i].value * matrix2.elements[j].value;
            }
        }
    }

    // Converting temporary matrix into sparse matrix
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            if (tempMatrix[i][j] != 0) {
                result.numElements++;
                result.elements = (struct SparseElement *)realloc(result.elements, result.numElements * sizeof(struct SparseElement));
                result.elements[result.numElements - 1].row = i;
                result.elements[result.numElements - 1].col = j;
                result.elements[result.numElements - 1].value = tempMatrix[i][j];
            }
        }
    }

    // Freeing temporary matrix memory
    for (int i = 0; i < matrix1.rows; i++) {
        free(tempMatrix[i]);
    }
    free(tempMatrix);

    return result;
}

// Function to display a sparse matrix
void displaySparseMatrix(struct SparseMatrix matrix) {
    int k = 0;
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (k < matrix.numElements && matrix.elements[k].row == i && matrix.elements[k].col == j) {
                printf("%d ", matrix.elements[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct SparseMatrix matrix1, matrix2;
    int numElements;

    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &matrix1.rows, &matrix1.cols);

    printf("Enter the number of non-zero elements in matrix 1: ");
    scanf("%d", &numElements);

    matrix1.numElements = numElements;
    matrix1.elements = (struct SparseElement *)malloc(numElements * sizeof(struct SparseElement));

    printf("Enter the row, column, and value for each non-zero element in matrix 1:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d %d %d", &matrix1.elements[i].row, &matrix1.elements[i].col, &matrix1.elements[i].value);
    }

    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &matrix2.rows, &matrix2.cols);

    printf("Enter the number of non-zero elements in matrix 2: ");
    scanf("%d", &numElements);

    matrix2.numElements = numElements;
    matrix2.elements = (struct SparseElement *)malloc(numElements * sizeof(struct SparseElement));

    printf("Enter the row, column, and value for each non-zero element in matrix 2:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d %d %d", &matrix2.elements[i].row, &matrix2.elements[i].col, &matrix2.elements[i].value);
    }

    struct SparseMatrix result = multiplySparseMatrices(matrix1, matrix2);

    printf("\nMatrix 1:\n");
    displaySparseMatrix(matrix1);

    printf("\nMatrix 2:\n");
    displaySparseMatrix(matrix2);

    printf("\nResultant Matrix:\n");
    displaySparseMatrix(result);

    // Freeing memory
    free(matrix1.elements);
    free(matrix2.elements);
    free(result.elements);

    return 0;
}
