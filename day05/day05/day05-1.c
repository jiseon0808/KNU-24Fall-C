#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	int* snum;
	char** name;
	int* score;

	printf("�л� �� �Է� : \n");
	scanf_s("%d", &N);

	snum = (int*)malloc(N * sizeof(int));
	score = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < N; i++) {
		printf("%d��° �л� ���� �Է�:\n", i + 1);
		printf("�й�: \n");
		scanf_s("%d", &snum[i]);

		printf("�̸�: \n");
		scanf_s("%s", name[i], 100);
		
		printf("����: \n");
		scanf_s("%d", &score[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("�й�: %d, �̸�: %s, ����: %d\n", snum[i], name[i], score[i]);
	}

	free(snum);
	free(score);
	for (int i = 0; i < N; i++) {
		free(name[i]);
	}
	free(name);
	return 0;
}
