#include <stdio.h>
#include <string.h>

void reverse(char* s);

int main() {
    char str[100];

    printf("���ڿ��� �Է��ϼ��� : ");
    scanf_s("%s", str, (unsigned int)sizeof(str));

    reverse(str);

    printf("�������� ���ڿ� : %s\n", str);
    return 0;
}

void reverse(char* s) {
    int len = strlen(s);
    char temp;


    for (int i = 0; i < len / 2; ++i) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}