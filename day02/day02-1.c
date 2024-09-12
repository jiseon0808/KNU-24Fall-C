#include <stdio.h>

int main()
{
	int x;
	double num1, num2, result;
	printf("원하는 기능을 입력하시오.\n");
	printf("1. 더하기  2. 빼기  3. 곱하기  4. 나누기");
	scanf_s("%d", &x);
	printf("숫자 1을 입력하세요.\n");
	scanf_s("%lf", &num1);
	printf("숫자 2를 입력하세요.\n");
	scanf_s("%lf", &num2);

	if (x == 1) {
		result = num1 + num2;

	}
	else if (x == 2) {
		result = num1 - num2;
	}
	else if (x == 3) {
		result = num1 * num2;
	}
	else if (x == 4) {
		result = num1 / num2;
	}
	else {
		printf("잘못 입력 하셨습니다.\n");
	}
	printf("result = %lf\n", result);
	return 0;
}