#include <gtest\gtest.h>

#include "Lab1.h"

TEST(solutionTest, Normal) {
    int k = 0;
    const int n = 5, m = 4;
    int** matr = matr_create(n, m);
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matr[i][j] = k;
            k++;
        }
    }
    EXPECT_EQ(solution(matr, n, m), 46);
}
TEST(solutionTest, OneOnOne) {
    const int n = 1, m = 1;
    int** matr = matr_create(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matr[i][j] = 1;
        }
    }
    EXPECT_EQ(solution(matr, n, m), 1);
}
TEST(solutionTest, AllSame) {
    const int n = 3, m = 4;
    int** matr = matr_create(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matr[i][j] = 1;
        }
    }
    EXPECT_EQ(solution(matr, n, m), 6);
}
TEST(solutionTest, Empty) {
    const int n = 0, m = 0;
    int** matr = matr_create(n, m);
    EXPECT_EQ(solution(matr, n, m), NULL);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}