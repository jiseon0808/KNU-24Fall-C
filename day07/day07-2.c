#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    double x, y = 0;
    double PI, r;
    int count = 0, circle = 0, cnt = 0;
    srand(time(NULL));


    for (int i = 1; i <= 100; i++) {
        circle = 0;
        cnt = 0;

        while (count < 10000000) {
            x = (double)rand() / (double)RAND_MAX;
            y = (double)rand() / (double)RAND_MAX;
            if (sqrt(pow(x, 2) + pow(y, 2) < 1)) {
                circle++;
            }
            count++;
            cnt++;
        }

        count = 0;
        PI = 4 * ((double)circle / (double)cnt);
        printf("%3d%% 진행, 원주율 : %lf ", i, PI);

        for (int j = 0; j < i / 5; j++)
            printf("■");

        for (int a = 0; a < 20 - i / 5; a++)
            printf("□");

        printf("\n");
    }

    printf("\n최종 원주율 : %lf\n", PI);
    return 0;
}
