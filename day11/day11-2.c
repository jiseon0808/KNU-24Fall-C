#include <stdio.h>
#include <math.h>

// 적분 계산 함수
void calculate_integral(int start, int end, int max_iterations) {
    double result = 0.0;

    // 구간 반복
    for (int iteration = 0; iteration <= max_iterations; iteration++) {
        int segments = pow(2, iteration); // 현재 반복에서의 구간 개수
        double width = (double)(end - start) / segments; // 각 직사각형의 너비

        result = 0.0; // 결과 초기화

        // 적분 구간에서 직사각형 넓이 계산
        for (int segment = 0; segment < segments; segment++) {
            double x = start + segment * width; // 현재 x 값
            double fx = log10(1.0 / x) + sin(x); // 함수 값 계산
            result += fx * width; // 넓이 누적
        }

        // 결과 출력
        printf("구간 개수: %d, 적분 결과: %.6f\n", segments, fabs(result));
    }
}

int main() {
    int start = 10, end = 30, iterations;

    // 사용자 입력
    printf("적분 시작 값: %d\n", start);
    printf("적분 끝 값: %d\n", end);
    printf("최대 반복 횟수 (2^n 형태): ");
    scanf_s("%d", &iterations);

    // 적분 수행
    calculate_integral(start, end, iterations);

    return 0;
}
