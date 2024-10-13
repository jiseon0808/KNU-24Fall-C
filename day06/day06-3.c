#include <stdio.h>
int main(){
    FILE* fp = NULL;
    fp = fopen("data.txt", "rt");

    int n1, n2, n3;
    while (fscanf(fp, "%d %d %d", &n1, &n2, &n3) != EOF) {
        printf("n1 = %d, n1 = %d, n1 = %d\n", n1, n2, n3);
    }

    fclose(fp);
    return 0;
}
