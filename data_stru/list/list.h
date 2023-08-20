//list.h:单链表的声明
#ifndef __LIST_H
#define __LIST_H
//包含公共的头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述节点属性的结构体
typedef struct node {
    int data; //节点数据
    struct node *next;//保存下一个节点的首地址
}node_t;
//声明描述整个单链表的结构体
typedef struct list  {
    struct node *head; //保存头结点的首地址
    struct node *tail; //保存尾节点的首地址
}list_t;
extern void list_init(list_t *list);//初始化
extern void list_deinit(list_t *list);//释放内存
extern void list_travel(list_t *list);//遍历
extern void list_add(list_t *list, int data);//顺序插
extern void list_add_first(list_t *list, int data);//前插
extern void list_add_last(list_t *list, int data);//后插
extern void list_del(list_t *list, int data);//删除data所在的节点
#endif
