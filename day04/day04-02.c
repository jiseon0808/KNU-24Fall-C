#include <stdio.h>

void swap(int* pvar1, int* pvar2) {
	int var1_ = *pvar1;
	*pvar1 = *pvar2;
	*pvar2 = *var1_;
}

int main() {
	int var1 = 10, var2 = 20;

	printf("var1 = %d var2 = %d", var1, var2);
	swap(&var1, &var2);
	printf("var1 = %d var2 = %d", var1, var2);
	return 0;
}