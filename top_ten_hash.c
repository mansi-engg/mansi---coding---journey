#include <stdio.h>
#include <string.h>

int main() {
    char hashtags[10][50] = {
        "#DataScience",
        "#AI",
        "#MachineLearning",
        "#Python",
        "#BigData",
        "#DeepLearning",
        "#Analytics",
        "#Technology",
        "#Coding",
        "#DataAnalysis"
    };

    char temp[50];
    int i, j;

    // Bubble Sort
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (strcmp(hashtags[j], hashtags[j + 1]) > 0) {
                strcpy(temp, hashtags[j]);
                strcpy(hashtags[j], hashtags[j + 1]);
                strcpy(hashtags[j + 1], temp);
            }
        }
    }

    printf("Top 10 Hashtags (Alphabetical Order):\n");

    for (i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, hashtags[i]);
    }

    return 0;
}