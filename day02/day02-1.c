#include <stdio.h>

int main()
{
	int x;
	double num1, num2, result;
	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1. ���ϱ�  2. ����  3. ���ϱ�  4. ������");
	scanf_s("%d", &x);
	printf("���� 1�� �Է��ϼ���.\n");
	scanf_s("%lf", &num1);
	printf("���� 2�� �Է��ϼ���.\n");
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
		printf("�߸� �Է� �ϼ̽��ϴ�.\n");
	}
	printf("result = %lf\n", result);
	return 0;
}