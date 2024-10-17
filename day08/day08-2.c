#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// 함수 선언
void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);  // void형 포인터를 사용하는 이유를 생각해보기
// int 함수는 정수값을 반환해줌, 배열 순회 후 이동한 위치나 이동 횟수를 반환하고 싶을 때 사용함.
// 단순히 배열을 순회하며 값을 출력하는 경우라면 반환값이 필요 없으므로 void 함수를 사용함.
// 어떠한 자료형으로도 변환될 수 있는 범용 포인터, 다양한 배열을 받을 수 있도록 설계하기 위해서.

int main() {
    int array[SIZE][SIZE];  // 10x10 배열 선언
    srand((unsigned int)time(NULL));  // 난수 생성기 초기화, seed값으로 현재시간 부여

    fillRandom(array);  // 배열 랜덤 초기화 (난수 채우기)
    printf("배열 출력:\n");
    printArray(array);  // 배열 출력 코드

    printf("\n배열 순회 시작:\n");
    movePointer(array);  // 포인터를 사용한 배열 순회

    return 0;
}

// 배열을 1~20 범위의 난수로 채우는 함수
void fillRandom(int(*array)[SIZE]) { // int(*)[SIZE] 구체적인 자료형 지정, fillRand() 함수는 항상 정수형 2차원 배열을 채워야함.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % 20 + 1;  // 1~20 범위의 난수 생성
        }
    }
}

// 배열을 출력하는 함수 (정렬된 출력)
void printArray(int(*array)[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", array[i][j]);  // 숫자 출력 후 공백 추가
        }
        printf("\n");  // 각 행이 끝날 때 줄바꿈
    }
}

// void 포인터를 사용한 배열 순회 함수
void movePointer(void* array) {
    int(*arr)[SIZE] = (int(*)[SIZE])array;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int value = *(*(arr + i) + j);  // 포인터 연산을 이용해 배열 요소 접근
            printf("현재 위치: (%d, %d), 값: %d\n", i, j, value);
        }
    }
}
