#include <stdio.h>

int main(){
    FILE* fp = NULL;
    fp = fopen("data.txt", "wt");

    fprintf(fp, "%d %d %d\n", 100, 200, 300);
    fprintf(fp, "%d %d %d\n", 400, 500, 600);

    fclose(fp);
    return 0;
}
