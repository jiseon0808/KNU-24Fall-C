#include <stdio.h>

int Fac(int num_r);

int main() {
    int num, result;

    printf("계산할 팩토리얼 값 입력 : ");
    scanf("%d", &num);
    result = Fac(num);
    printf("%d! = %d \n", num, result);

    return 0;
}

int Fac(int num2) {
    int fac_num;

    if (num2 == 1 || num2 == 0) {
        return 1;
    }
    else {
        fac_num = num2 * Fac(num2 - 1);
    }

    return fac_num;
}