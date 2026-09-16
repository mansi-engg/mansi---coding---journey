#include <stdio.h>

int main() {
    int degree, i;

    printf("Enter the degree of polynomial: ");
    scanf("%d", &degree);

    int coeff[degree + 1];

    printf("Enter coefficients from highest degree to constant:\n");
    for (i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff[i]);
    }

    printf("\nPolynomial: ");

    for (i = degree; i >= 0; i--) {
        if (coeff[i] != 0) {
            if (i != degree && coeff[i] > 0)
                printf(" + ");

            if (i == 0)
                printf("%d", coeff[i]);
            else if (i == 1)
                printf("%dx", coeff[i]);
            else
                printf("%dx^%d", coeff[i], i);
        }
    }

    return 0;
}