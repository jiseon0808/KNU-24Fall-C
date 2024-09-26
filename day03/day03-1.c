#include <stdio.h>

int main() {
	int input;
	printf("소수인지 확인할 수를 입력해 주세요. : ");
	scanf_s("%d", &input);

	if (check_primenum_func(input)) {
		printf("입력한 수는 소수입니다.");
	}
	else {
		printf("입력한 수는 소수가 아닙니다.");
	}
	return 0;
}

int check_primenum_func(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}