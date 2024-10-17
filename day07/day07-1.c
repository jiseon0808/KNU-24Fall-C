#include <stdio.h>

int main() {
    int n;
    printf("몇층? : ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - 1; j++) {
            printf(" ");
        }
        for (int k = 0; k < i * 2 + 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
