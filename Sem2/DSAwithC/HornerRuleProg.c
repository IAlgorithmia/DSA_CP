#include <stdio.h>
int main() {
    int n, i, x;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);

    int coeffs[n+1];
    printf("Enter the coefficients in decreasing order of degree:\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &coeffs[i]);
    }

    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = coeffs[0];
    for (i = 1; i <= n; i++) {
        result = result * x + coeffs[i];
    }

    printf("The value of the polynomial at x=%d is %d\n", x, result);

    return 0;
}
