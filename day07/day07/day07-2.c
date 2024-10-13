#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    double x = 0; 
    double y = 0;

    int count = 0, circle = 0;

    srand(time(NULL));

    while (1) {
        x = (double)rand() / (double)RAND_MAX;
        y = (double)rand() / (double)RAND_MAX;
        count++;
        if ((x * x) + (y * y) < 1) {
            circle++;
        }
        printf("%d%% 진행 · 원주율 : %f\n", , count/4, (circle / count) * 4);

    }

    return 0;
}
