#include <stdio.h>
#include <string.h>


struct Product {
    int id, price;
    char name[20];
};

void printProduct(struct Product p) {
    printf("상품 ID : %d\n", p.id);
    printf("상품명 : %s\n", p.name);
    printf("가격 : %d원\n", p.price);
}

int main() {
    struct Product products[5];
    int count = 0;

    for (int i = 0; i < 5; i++) {
        printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");
        printf("상품 ID: ");
        scanf_s("%d", &products[i].id);

        if (products[i].id == 0) {
            break;
        }

        printf("상품명: ");
        getchar();
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0';
        
        printf("가격: ");
        scanf_s("%d", &products[i].price);
        printf("\n");

        count++;  // 입력된 상품 개수 증가
    }


    printf("\n[ 입력된 상품 목록 ]\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}
