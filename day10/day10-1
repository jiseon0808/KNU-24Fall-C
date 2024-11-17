#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    char name[20];
    int score;
    struct NODE* link;
};

struct NODE* head = NULL;

// 노드 생성
struct NODE* create_node(char* name, int score) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy_s(new_node->name, sizeof(new_node->name), name);
    new_node->score = score;
    new_node->link = NULL;
    return new_node;
}

// 정렬된 위치에 노드 삽입
void insert_node_sorted(struct NODE* new_node) {
    if (head == NULL || strcmp(new_node->name, head->name) < 0) {
        new_node->link = head;
        head = new_node;
    }
    else {
        struct NODE* cur = head;
        while (cur->link != NULL && strcmp(cur->link->name, new_node->name) < 0) {
            cur = cur->link;
        }
        new_node->link = cur->link;
        cur->link = new_node;
    }
}

// 노드 출력 (전체 학생 출력)
void print_nodes() {
    struct NODE* cur = head;
    while (cur != NULL) {
        printf("%s : %d\n", cur->name, cur->score);
        cur = cur->link;
    }
}

// 노드 삭제 (학생 삭제)
int delete_node(char* name) {
    struct NODE* cur = head;
    struct NODE* prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                head = cur->link;
            }
            else {
                prev->link = cur->link;
            }
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->link;
    }
    return 0;
}

int main() {
    int choice, score;
    char name[20];

    while (1) {
        printf("\n1. 학생의 성적을 입력\n2. 학생 정보 삭제\n3. 프로그램 종료\ninput: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            printf("학생 이름: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            printf("%s의 성적: ", name);
            scanf_s("%d", &score);
            struct NODE* new_node = create_node(name, score);
            insert_node_sorted(new_node);

            printf("\n전체 학생 목록:\n");
            print_nodes();
        }
        else if (choice == 2) {
            printf("삭제할 학생 이름: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            if (delete_node(name)) {
                printf("%s 학생이 삭제되었습니다.\n", name);
            }
            else {
                printf("학생을 찾을 수 없습니다.\n");
            }

            printf("\n전체 학생 목록:\n");
            print_nodes();
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("잘못된 입력입니다. 다시 시도해주세요.\n");
        }
    }

    return 0;
}
