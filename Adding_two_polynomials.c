#include <stdio.h>

int main() {
    int p1[20], p2[20], sum[20];
    int d1, d2, max, i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &d1);

    printf("Enter coefficients of first polynomial:\n");
    for (i = d1; i >= 0; i--)
        scanf("%d", &p1[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &d2);

    printf("Enter coefficients of second polynomial:\n");
    for (i = d2; i >= 0; i--)
        scanf("%d", &p2[i]);

    max = (d1 > d2) ? d1 : d2;

    for (i = 0; i <= max; i++)
        sum[i] = p1[i] + p2[i];

    printf("\nSum of polynomials:\n");

    for (i = max; i >= 0; i--) {
        if (sum[i] != 0) {
            if (i == 0)
                printf("%d", sum[i]);
            else if (i == 1)
                printf("%dx", sum[i]);
            else
                printf("%dx^%d", sum[i], i);

            if (i > 0)
                printf(" + ");
        }
    }

    return 0;
}