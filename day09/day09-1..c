#include <stdio.h>

// 3차원 벡터 정의
struct vector {
    float x, y, z;
};

struct vector add(struct vector v1, struct vector v2) {
    struct vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

struct vector cha(struct vector v1, struct vector v2) {
    struct vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

float dot(struct vector v1, struct vector v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

struct vector cross(struct vector v1, struct vector v2) {
    struct vector result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

int main() {
    struct vector v1, v2;
    int choice;
   
    printf("첫번째 벡터 (x, y, z) : ");
    scanf_s("%f %f %f", &v1.x, &v1.y, &v1.z);
    printf("두번째 벡터 (x, y, z) : ");
    scanf_s("%f %f %f", &v2.x, &v2.y, &v2.z);

    printf("\n입력된 첫번째 벡터: %.1f, %.1f, %.1f\n", v1.x, v1.y, v1.z);
    printf("입력된 두번째 벡터: %.1f, %.1f, %.1f\n", v2.x, v2.y, v2.z);

    printf("\n------------\n");
    printf("1. 벡터의 합\n");
    printf("2. 벡터의 차\n");
    printf("3. 벡터의 외적\n");
    printf("4. 벡터의 내적\n");
    printf("5. 종료\n");
    printf("--------------\n");

    printf("명령 입력: ");
    scanf_s("%d", &choice);


    switch (choice) {
    case 1: {
        struct vector result = add(v1, v2);
        printf("벡터의 합: (%.1f, %.1f, %.1f)\n", result.x, result.y, result.z);
        break;
    }
    case 2: {
        struct vector result = cha(v1, v2);
        printf("벡터의 차: (%.1f, %.1f, %.1f)\n", result.x, result.y, result.z);
        break;
    }
    case 3: {
        struct vector result = cross(v1, v2);
        printf("벡터의 외적은\nx: %.1f, y: %.1f, z: %.1f\n",
            result.x, result.y, result.z);
        break;
    }
    case 4: {
        float result = dot(v1, v2);
        printf("벡터의 내적은 vec1 · vec2 = %.1f\n", result);
        break;
    }
    default:
        printf("종료.\n");
    }

    return 0;
}
