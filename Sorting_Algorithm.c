#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    char names[100][50];
    char key[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter student names:\n");

    for (i = 0; i < n; i++) {
        scanf("%49s", names[i]);
    }

    // Insertion Sort
    for (i = 1; i < n; i++) {
        strcpy(key, names[i]);
        j = i - 1;

        while (j >= 0 && strcmp(names[j], key) > 0) {
            strcpy(names[j + 1], names[j]);
            j--;
        }

        strcpy(names[j + 1], key);
    }

    printf("\nStudent Names in Alphabetical Order:\n");

    for (i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}