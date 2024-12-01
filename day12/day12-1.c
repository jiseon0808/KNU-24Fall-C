#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int left_counts[10010] = {0}, right_counts[10010] = {0};
    int unique_left = 0, unique_right = 0;

    // 오른쪽 배열의 초기 고유 토핑 개수 계산
    for (int i = 0; i < topping_len; i++) {
        if (right_counts[topping[i]] == 0) {
            unique_right++;
        }
        right_counts[topping[i]]++;
    }

    // 각 인덱스를 기준으로 왼쪽과 오른쪽 고유 토핑 개수를 비교
    for (int i = 0; i < topping_len; i++) {
        right_counts[topping[i]]--;
        if (right_counts[topping[i]] == 0) {
            unique_right--;
        }
        if (left_counts[topping[i]] == 0) {
            unique_left++;
        }
        left_counts[topping[i]]++;

        // 고유 토핑 개수가 같으면 경우의 수 증가
        if (unique_left == unique_right) {
            answer++;
        }
    }
    return answer;
}
