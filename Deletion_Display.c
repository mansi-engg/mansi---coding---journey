#include <stdio.h>

int main() {
    int arr[100], n, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display
    printf("\nArray elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Deletion
    printf("\n\nEnter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!");
    } else {
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("Element deleted successfully.\n");

        // Display after deletion
        printf("Array after deletion: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}