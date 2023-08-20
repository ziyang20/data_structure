//list.h:双链表的各种声明
#ifndef __LIST_H
#define __LIST_H
//包含公共的头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述节点信息的结构体
typedef struct node {
    int data; //数据
    struct node *next;//保存下一个节点的首地址
    struct node *prev; //保存上一个节点的首地址
}node_t;
//声明描述整个链表的结构体
typedef struct list {
    struct node head;//头节点
    struct node tail;//尾节点
}list_t;
extern void list_init(list_t *list);//初始化函数
extern void list_deinit(list_t *list);//释放内存函数
extern int list_empty(list_t *list);//判断空
extern int list_size(list_t *list);//获取有效节点个数函数
extern void list_add(list_t *list, int data);//顺序插
extern void list_add_first(list_t *list, int data);//前插
extern void list_add_last(list_t *list, int data);//后插
extern void list_del(list_t *list, int data);//删除指定节点
extern void list_del_first(list_t *list);//只删除第一个节点
extern void list_del_last(list_t *list);//只删除最后一个节点
extern int list_get(list_t *list, int index);//根据节点编号获取节点数据
#endif
