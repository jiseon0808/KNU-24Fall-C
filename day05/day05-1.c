#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	int* snum;
	char** name;
	int* score;

	printf("학생 수 입력 : \n");
	scanf_s("%d", &N);

	snum = (int*)malloc(N * sizeof(int));
	score = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < N; i++) {
		printf("%d번째 학생 정보 입력:\n", i + 1);
		printf("학번: \n");
		scanf_s("%d", &snum[i]);

		printf("이름: \n");
		scanf_s("%s", name[i], 100);
		
		printf("점수: \n");
		scanf_s("%d", &score[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("학번: %d, 이름: %s, 점수: %d\n", snum[i], name[i], score[i]);
	}

	free(snum);
	free(score);
	for (int i = 0; i < N; i++) {
		free(name[i]);
	}
	free(name);
	return 0;
}
