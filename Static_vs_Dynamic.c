#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    // Static Data Structure
    int staticArray[5] = {10, 20, 30, 40, 50};

    printf("Static Array:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", staticArray[i]);
    }

    // Dynamic Data Structure
    printf("\n\nEnter size for Dynamic Array: ");
    scanf("%d", &n);

    int *dynamicArray = (int *)malloc(n * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    printf("Dynamic Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", dynamicArray[i]);
    }

    free(dynamicArray);

    return 0;
}