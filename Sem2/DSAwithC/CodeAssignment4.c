#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct {
    int coefficient;
    int exponent;
} Term;

// Structure to represent a polynomial
typedef struct {
    int degree;
    Term *terms;
} Polynomial;

// Function to create a new polynomial
Polynomial createPolynomial(int degree) {
    Polynomial poly;
    poly.degree = degree;
    poly.terms = (Term *)malloc((degree + 1) * sizeof(Term));
    return poly;
}

// Function to input a polynomial
void inputPolynomial(Polynomial *poly) {
    printf("Enter the coefficients and exponents for the polynomial:\n");
    for (int i = poly->degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &(poly->terms[i].coefficient));
        poly->terms[i].exponent = i;
    }
}

// Function to display a polynomial
void displayPolynomial(Polynomial poly) {
    for (int i = poly.degree; i >= 0; i--) {
        if (poly.terms[i].coefficient != 0) {
            printf("%dx^%d", poly.terms[i].coefficient, poly.terms[i].exponent);
            if (i != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

// Function to subtract two polynomials
Polynomial subtractPolynomials(Polynomial poly1, Polynomial poly2) {
    int degree = (poly1.degree > poly2.degree) ? poly1.degree : poly2.degree;
    Polynomial result = createPolynomial(degree);
    
    for (int i = 0; i <= poly1.degree; i++) {
        result.terms[i].coefficient += poly1.terms[i].coefficient;
    }
    
    for (int i = 0; i <= poly2.degree; i++) {
        result.terms[i].coefficient -= poly2.terms[i].coefficient;
    }
    
    return result;
}

// Function to multiply two polynomials
Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2) {
    int degree = poly1.degree + poly2.degree;
    Polynomial result = createPolynomial(degree);
    
    for (int i = 0; i <= poly1.degree; i++) {
        for (int j = 0; j <= poly2.degree; j++) {
            int coefficient = poly1.terms[i].coefficient * poly2.terms[j].coefficient;
            int exponent = poly1.terms[i].exponent + poly2.terms[j].exponent;
            
            result.terms[exponent].coefficient += coefficient;
        }
    }
    
    return result;
}

int main() {
    int degree1, degree2;
    
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    Polynomial poly1 = createPolynomial(degree1);
    inputPolynomial(&poly1);
    
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    Polynomial poly2 = createPolynomial(degree2);
    inputPolynomial(&poly2);
    
    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    Polynomial subtraction = subtractPolynomials(poly1, poly2);
    printf("\nSubtraction: ");
    displayPolynomial(subtraction);
    
    Polynomial multiplication = multiplyPolynomials(poly1, poly2);
    printf("Multiplication: ");
    displayPolynomial(multiplication);
    
    // Free memory allocated for polynomials
    free(poly1.terms);
    free(poly2.terms);
    free(subtraction.terms);
    free(multiplication.terms);
    
    return 0;
}
