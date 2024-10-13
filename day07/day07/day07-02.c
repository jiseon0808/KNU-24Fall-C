#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(void) {
    double x, y;
    int count = 0, circle = 0;
    int a = 0; 

    srand(time(NULL)); 

    while (a <= 10000000) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        count++;

        
        if ((x * x) + (y * y) <= 1) {
            circle++;
        }

        
        if (count % 10000 == 0) {
            a++; 
            double pi_estimate = (double)circle / count * 4;

            
            printf("%d%% 진행\t원주율 : %.6f\t", a, pi_estimate);

            
            for (int i = 0; i < a; i++) {
                printf("■"); 
            }
            printf("\n");
        }
    }

    printf("최종 원주율 : %.6f\n", (double)circle / count * 4);
    return 0;
}
