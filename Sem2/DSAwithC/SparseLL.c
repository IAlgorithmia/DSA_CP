#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int val;
    struct Node* next;
};

struct SparseMatrix {
    int rows;
    int cols;
    struct Node* head;
};

void insertNode(struct SparseMatrix* matrix, int row, int col, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;

    if (matrix->head == NULL) {
        matrix->head = newNode;
    } else {
        struct Node* curr = matrix->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void displayMatrix(struct SparseMatrix* matrix) {
    struct Node* curr = matrix->head;
    printf("Row\tColumn\tValue\n");
    while (curr != NULL) {
        printf("%d\t%d\t%d\n", curr->row, curr->col, curr->val);
        curr = curr->next;
    }
}

struct SparseMatrix* transpose(struct SparseMatrix* matrix) {
    struct SparseMatrix* transposedMatrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    transposedMatrix->rows = matrix->cols;
    transposedMatrix->cols = matrix->rows;
    transposedMatrix->head = NULL;

    struct Node* curr = matrix->head;
    while (curr != NULL) {
        insertNode(transposedMatrix, curr->col, curr->row, curr->val);
        curr = curr->next;
    }

    return transposedMatrix;
}

struct SparseMatrix* fastTranspose(struct SparseMatrix* matrix) {
    struct SparseMatrix* transposedMatrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    transposedMatrix->rows = matrix->cols;
    transposedMatrix->cols = matrix->rows;
    transposedMatrix->head = NULL;

    int* rowSize = (int*)calloc(matrix->cols, sizeof(int));
    int* rowStart = (int*)calloc(matrix->cols, sizeof(int));

    struct Node* curr = matrix->head;
    while (curr != NULL) {
        rowSize[curr->col]++;
        curr = curr->next;
    }

    rowStart[0] = 0;
    for (int i = 1; i < matrix->cols; i++) {
        rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
    }

    curr = matrix->head;
    while (curr != NULL) {
        int pos = rowStart[curr->col];
        insertNode(transposedMatrix, curr->col, curr->row, curr->val);
        rowStart[curr->col]++;
        curr = curr->next;
    }

    free(rowSize);
    free(rowStart);

    return transposedMatrix;
}

struct SparseMatrix* addSparseMatrices(struct SparseMatrix* matrix1, struct SparseMatrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrices are not of the same size. Addition not possible.\n");
        return NULL;
    }

    struct SparseMatrix* resultMatrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    resultMatrix->rows = matrix1->rows;
    resultMatrix->cols = matrix1->cols;
    resultMatrix->head = NULL;

    struct Node* curr1 = matrix1->head;
    struct Node* curr2 = matrix2->head;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->row < curr2->row || (curr1->row == curr2->row && curr1->col < curr2->col)) {
            insertNode(resultMatrix, curr1->row, curr1->col, curr1->val);
            curr1 = curr1->next;
        } else if (curr1->row > curr2->row || (curr1->row == curr2->row && curr1->col > curr2->col)) {
            insertNode(resultMatrix, curr2->row, curr2->col, curr2->val);
            curr2 = curr2->next;
        } else {
            int sum = curr1->val + curr2->val;
            if (sum != 0) {
                insertNode(resultMatrix, curr1->row, curr1->col, sum);
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    while (curr1 != NULL) {
        insertNode(resultMatrix, curr1->row, curr1->col, curr1->val);
        curr1 = curr1->next;
    }

    while (curr2 != NULL) {
        insertNode(resultMatrix, curr2->row, curr2->col, curr2->val);
        curr2 = curr2->next;
    }

    return resultMatrix;
}

void freeSparseMatrix(struct SparseMatrix* matrix) {
    struct Node* curr = matrix->head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(matrix);
}

int main() {
    struct SparseMatrix matrix1;
    matrix1.rows = 3;
    matrix1.cols = 3;
    matrix1.head = NULL;

    insertNode(&matrix1, 0, 1, 5);
    insertNode(&matrix1, 0, 2, 0);
    insertNode(&matrix1, 1, 0, 0);
    insertNode(&matrix1, 1, 2, 7);
    insertNode(&matrix1, 2, 0, 3);
    insertNode(&matrix1, 2, 1, 9);
    insertNode(&matrix1, 2, 2, 0);

    printf("Sparse Matrix 1:\n");
    displayMatrix(&matrix1);

    struct SparseMatrix* transposedMatrix1 = transpose(&matrix1);
    printf("\nTransposed Matrix 1:\n");
    displayMatrix(transposedMatrix1);

    struct SparseMatrix* fastTransposedMatrix1 = fastTranspose(&matrix1);
    printf("\nFast Transposed Matrix 1:\n");
    displayMatrix(fastTransposedMatrix1);

    struct SparseMatrix matrix2;
    matrix2.rows = 3;
    matrix2.cols = 3;
    matrix2.head = NULL;

    insertNode(&matrix2, 0, 1, 0);
    insertNode(&matrix2, 0, 2, 2);
    insertNode(&matrix2, 1, 0, 4);
    insertNode(&matrix2, 1, 1, 0);
    insertNode(&matrix2, 2, 0, 0);
    insertNode(&matrix2, 2, 1, 6);
    insertNode(&matrix2, 2, 2, 0);

    printf("\nSparse Matrix 2:\n");
    displayMatrix(&matrix2);

    struct SparseMatrix* transposedMatrix2 = transpose(&matrix2);
    printf("\nTransposed Matrix 2:\n");
    displayMatrix(transposedMatrix2);

    struct SparseMatrix* fastTransposedMatrix2 = fastTranspose(&matrix2);
    printf("\nFast Transposed Matrix 2:\n");
    displayMatrix(fastTransposedMatrix2);

    struct SparseMatrix* sumMatrix = addSparseMatrices(&matrix1, &matrix2);
    printf("\nSum of Sparse Matrices:\n");
    displayMatrix(sumMatrix);

    freeSparseMatrix(transposedMatrix1);
    freeSparseMatrix(fastTransposedMatrix1);
    freeSparseMatrix(transposedMatrix2);
    freeSparseMatrix(fastTransposedMatrix2);
    freeSparseMatrix(sumMatrix);

    return 0;
}
