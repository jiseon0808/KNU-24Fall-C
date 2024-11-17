#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { BRONZE = 3, SILVER = 2, GOLD = 1 } Rank;

struct Customer {
    char name[20];
    Rank rank;
    int order_amount;
    int point;
    struct Customer* link;
};

struct Customer* head = NULL;

// 고객 노드 생성
struct Customer* create_customer(char* name, Rank rank, int order_amount, int point) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy_s(new_customer->name, sizeof(new_customer->name), name);
    new_customer->rank = rank;
    new_customer->order_amount = order_amount;
    new_customer->point = point;
    new_customer->link = NULL;
    return new_customer;
}

// 고객 우선순위 비교 함수
int compare_customers(struct Customer* c1, struct Customer* c2) {
    if (c1->rank != c2->rank)
        return c1->rank - c2->rank; // 등급이 낮을수록 우선
    if (c1->order_amount != c2->order_amount)
        return c2->order_amount - c1->order_amount; // 주문량이 많을수록 우선
    return c2->point - c1->point; // 포인트가 많을수록 우선
}

// 우선순위에 맞춰 고객을 삽입
void insert_customer_sorted(struct Customer* new_customer) {
    if (head == NULL || compare_customers(new_customer, head) < 0) {
        new_customer->link = head;
        head = new_customer;
    }
    else {
        struct Customer* cur = head;
        while (cur->link != NULL && compare_customers(new_customer, cur->link) >= 0) {
            cur = cur->link;
        }
        new_customer->link = cur->link;
        cur->link = new_customer;
    }
}

// 고객 출력 (전체 고객 출력)
void print_customers() {
    struct Customer* cur = head;
    while (cur != NULL) {
        printf("이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n",
            cur->name, cur->rank, cur->order_amount, cur->point);
        cur = cur->link;
    }
}

// 고객 삭제
int delete_customer(char* name) {
    struct Customer* cur = head;
    struct Customer* prev = NULL;

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
    int choice;
    char name[20];
    int rank, order_amount, point;

    while (1) {
        printf("\n1. 고객 추가\n2. 고객 삭제\n3. 전체 고객 출력\n4. 종료\n입력: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            printf("고객 이름: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            printf("고객 등급 (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf_s("%d", &rank);
            printf("주문량: ");
            scanf_s("%d", &order_amount);
            printf("포인트: ");
            scanf_s("%d", &point);
            struct Customer* new_customer = create_customer(name, (Rank)rank, order_amount, point);
            insert_customer_sorted(new_customer);

            printf("\n전체 고객 목록:\n");
            print_customers();
        }
        else if (choice == 2) {
            printf("삭제할 고객 이름: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            if (delete_customer(name)) {
                printf("%s 고객이 삭제되었습니다.\n", name);
            }
            else {
                printf("해당 고객을 찾을 수 없습니다.\n");
            }

            printf("\n전체 고객 목록:\n");
            print_customers();
        }
        else if (choice == 3) {
            printf("\n전체 고객 목록:\n");
            print_customers();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("잘못된 입력입니다. 다시 시도해주세요.\n");
        }
    }

    return 0;
}
