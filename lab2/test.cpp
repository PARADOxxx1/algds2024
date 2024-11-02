#include "pch.h"
#include "Lab2.h"

extern Node* root;
extern Node* NIL;

TEST(RedBlackTreeTest, InsertTest) {
    initNil();
    root = NIL;
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);

    EXPECT_STREQ(printTree(), "10(Black) 15(Red) 20(Black) 25(Red) 30(Black) ");
}

TEST(RedBlackTreeTest, DeleteTest) {
    initNil();
    root = NIL;
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);

    deleteNode(20);

    EXPECT_STREQ(printTree(), "10(Black) 15(Red) 25(Black) 30(Black) ");
}

TEST(RedBlackTreeTest, InsertDuplicateTest) {
    initNil();
    root = NIL;
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);
    insert(20);

    EXPECT_STREQ(printTree(), "10(Black) 15(Red) 20(Black) 20(Red) 25(Black) 30(Red) ");
}

TEST(RedBlackTreeTest, DeleteNonExistentTest) {
    initNil();
    root = NIL;
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);

    deleteNode(40);

    EXPECT_STREQ(printTree(), "10(Black) 15(Red) 20(Black) 25(Red) 30(Black) ");
}

TEST(RedBlackTreeTest, InsertAndDeleteTest) {
    initNil();
    root = NIL;
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);

    deleteNode(20);
    deleteNode(10);

    EXPECT_STREQ(printTree(), "15(Black) 25(Black) 30(Black) ");
}

TEST(RedBlackTreeTest, InsertAndDeleteRootTest) {
    initNil();
    root = NIL;
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);

    deleteNode(20);
    deleteNode(25);

    EXPECT_STREQ(printTree(), "10(Black) 15(Black) 30(Black) ");
}

TEST(RedBlackTreeTest, InsertAndDeleteAllTest) {
    initNil();
    root = NIL;
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);

    deleteNode(10);
    deleteNode(20);
    deleteNode(30);
    deleteNode(15);
    deleteNode(25);

    EXPECT_STREQ(printTree(), "");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}