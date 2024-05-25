#include "Lab1.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf_s("%d %d", &n, &m);
    int** field = matr_create(n, m);
    for (int i = 0; i < n; i++) {
        int* row = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            int cost;
            scanf_s("%d", &cost);
            row[j] = cost;
        }
        field[i] = row;
    }
    int ans = solution(field, n, m);
    printf("Answer: %d", ans);
    return 0;
}
