//tree.h:二叉树各种声明
#ifndef __TREE_H
#define __TREE_H
//包含公共的头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述节点属性的结构体
typedef struct node {
    int data; //数据
    struct node *left; //保存左节点的首地址
    struct node *right; //保存右节点首地址
}node_t;
//声明描述整个二叉树的结构体
typedef struct tree {
    struct node *root; //保存根节点的首地址
    int cnt; //保存节点个数
}tree_t;
extern void tree_travel(tree_t *tree); //遍历
extern void tree_clear(tree_t *tree); //清空所有节点
extern void tree_insert(tree_t *tree, int data);//插入新节点
extern void tree_del(tree_t *tree, int data);//删除指定节点
extern void tree_modify(tree_t *tree, int old_data, int new_data);//修改节点值
#endif
