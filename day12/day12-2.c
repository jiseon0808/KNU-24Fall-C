#include <stdio.h>

int solution(int n) {
    int energy = 0;

    while (n > 0) {
        if (n & 1) { // n이 홀수인 경우
            energy++;
            n--; // 1을 빼줌
        } else {
            n >>= 1; // n을 2로 나누기 (비트 연산)
        }
    }

    return energy;
}

int main() {
    int n = 5000;
    int result = solution(n);
    printf("결과: %d\n", result);
    return 0;
}
