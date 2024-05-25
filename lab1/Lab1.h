#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int** matr_create(int const n, int const m) {
    if (n == 0 || m == 0) return NULL;
    int** matr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matr[i] = (int*)malloc(m * sizeof(int));
    }
    return matr;
}

int solution(int** const field, int const n, int const m) {
    int** matr = matr_create(n, m);
    if (matr == NULL) return NULL;
    matr[n - 1][0] = field[n - 1][0];
    for (int i = 1; i < m; i++) {
        matr[n - 1][i] = matr[n - 1][i - 1] + field[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--) {
        matr[i][0] = matr[i + 1][0] + field[i][0];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j < m; j++) {
            matr[i][j] = MIN(matr[i + 1][j], matr[i][j - 1]) + field[i][j];
        }
    }
    return matr[0][m - 1];
}
