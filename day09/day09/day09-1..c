#include <stdio.h>

// 3���� ���� ����
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
   
    printf("ù��° ���� (x, y, z) : ");
    scanf_s("%f %f %f", &v1.x, &v1.y, &v1.z);
    printf("�ι�° ���� (x, y, z) : ");
    scanf_s("%f %f %f", &v2.x, &v2.y, &v2.z);

    printf("\n�Էµ� ù��° ����: %.1f, %.1f, %.1f\n", v1.x, v1.y, v1.z);
    printf("�Էµ� �ι�° ����: %.1f, %.1f, %.1f\n", v2.x, v2.y, v2.z);

    printf("\n------------\n");
    printf("1. ������ ��\n");
    printf("2. ������ ��\n");
    printf("3. ������ ����\n");
    printf("4. ������ ����\n");
    printf("5. ����\n");
    printf("--------------\n");

    printf("��� �Է�: ");
    scanf_s("%d", &choice);


    switch (choice) {
    case 1: {
        struct vector result = add(v1, v2);
        printf("������ ��: (%.1f, %.1f, %.1f)\n", result.x, result.y, result.z);
        break;
    }
    case 2: {
        struct vector result = cha(v1, v2);
        printf("������ ��: (%.1f, %.1f, %.1f)\n", result.x, result.y, result.z);
        break;
    }
    case 3: {
        struct vector result = cross(v1, v2);
        printf("������ ������\nx: %.1f, y: %.1f, z: %.1f\n",
            result.x, result.y, result.z);
        break;
    }
    case 4: {
        float result = dot(v1, v2);
        printf("������ ������ vec1 �� vec2 = %.1f\n", result);
        break;
    }
    default:
        printf("����.\n");
    }

    return 0;
}
