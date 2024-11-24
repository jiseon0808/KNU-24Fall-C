#include <stdio.h>
#include <math.h> // 헤더파일이 double 이여야함

int main(void) {
	int a, b, c;
	double D;

	printf("Ax^2 + Bx + C =0 의 계수 A, B, C를 입력하세요 : ");
	scanf_s("%d %d %d", &a, &b, &c);

	if (a == 0) {
		printf("2차 방정식이 아닙니다.");
	}
	else {
		D = b * b - 4 * a * c;

		if (D < 0) {
			printf("허근\n");
		}
		else if (D == 0) {
			printf("중근\n");
			printf("x=%g\n", (-b / (2.0 * a)));
		}
		else {
			printf("실근\n");
			printf("x=%g\n", (-b + sqrt(D)) / (2.0 * a));
			printf("x=%g\n", (-b - sqrt(D)) / (2.0 * a));
		}
	}
	return 0;
}
