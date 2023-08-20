//main.c:有序二叉树测试
#include "tree.h"
int main(void) {
    tree_t tree;
    tree.root = NULL;
    tree.cnt = 0;
    tree_insert(&tree, 50);
    tree_insert(&tree, 70);
    tree_insert(&tree, 60);
    tree_insert(&tree, 20);
    tree_insert(&tree, 40);
    tree_insert(&tree, 30);
    tree_insert(&tree, 10);
    tree_insert(&tree, 90);
    tree_insert(&tree, 80);
    tree_travel(&tree);
    tree_del(&tree, 40);
    tree_del(&tree, 40);
    tree_travel(&tree);
    tree_modify(&tree, 10, 520);
    tree_travel(&tree);
    tree_clear(&tree);
    tree_travel(&tree);
    return 0;
}
