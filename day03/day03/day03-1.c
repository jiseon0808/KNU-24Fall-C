#include <stdio.h>

int main() {
	int input;
	printf("�Ҽ����� Ȯ���� ���� �Է��� �ּ���. : ");
	scanf_s("%d", &input);

	if (check_primenum_func(input)) {
		printf("�Է��� ���� �Ҽ��Դϴ�.");
	}
	else {
		printf("�Է��� ���� �Ҽ��� �ƴմϴ�.");
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