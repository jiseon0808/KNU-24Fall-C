#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// �Լ� ����
void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);  // void�� �����͸� ����ϴ� ������ �����غ���
// int �Լ��� �������� ��ȯ����, �迭 ��ȸ �� �̵��� ��ġ�� �̵� Ƚ���� ��ȯ�ϰ� ���� �� �����.
// �ܼ��� �迭�� ��ȸ�ϸ� ���� ����ϴ� ����� ��ȯ���� �ʿ� �����Ƿ� void �Լ��� �����.
// ��� �ڷ������ε� ��ȯ�� �� �ִ� ���� ������, �پ��� �迭�� ���� �� �ֵ��� �����ϱ� ���ؼ�.

int main() {
    int array[SIZE][SIZE];  // 10x10 �迭 ����
    srand((unsigned int)time(NULL));  // ���� ������ �ʱ�ȭ, seed������ ����ð� �ο�

    fillRandom(array);  // �迭 ���� �ʱ�ȭ (���� ä���)
    printf("�迭 ���:\n");
    printArray(array);  // �迭 ��� �ڵ�

    printf("\n�迭 ��ȸ ����:\n");
    movePointer(array);  // �����͸� ����� �迭 ��ȸ

    return 0;
}

// �迭�� 1~20 ������ ������ ä��� �Լ�
void fillRandom(int(*array)[SIZE]) { // int(*)[SIZE] ��ü���� �ڷ��� ����, fillRand() �Լ��� �׻� ������ 2���� �迭�� ä������.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % 20 + 1;  // 1~20 ������ ���� ����
        }
    }
}

// �迭�� ����ϴ� �Լ� (���ĵ� ���)
void printArray(int(*array)[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", array[i][j]);  // ���� ��� �� ���� �߰�
        }
        printf("\n");  // �� ���� ���� �� �ٹٲ�
    }
}

// void �����͸� ����� �迭 ��ȸ �Լ�
void movePointer(void* array) {
    int(*arr)[SIZE] = (int(*)[SIZE])array;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int value = *(*(arr + i) + j);  // ������ ������ �̿��� �迭 ��� ����
            printf("���� ��ġ: (%d, %d), ��: %d\n", i, j, value);
        }
    }
}
