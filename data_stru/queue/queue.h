//queue.h:队列的声明
#ifndef __QUEUE_H
#define __QUEUE_H
//包含功能的头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述队列属性的结构体
typedef struct queue {
    int *arr; //首地址
    int cap;//容量
    int size; //有效数据个数
    int rear; //用于入队
    int front; //用于出队
}queue_t;
extern void queue_init(queue_t *queue, int cap);//初始化
extern void queue_deinit(queue_t *queue);//释放内存
extern int queue_full(queue_t *queue);//判断满
extern int queue_empty(queue_t *queue);//判断空
extern void queue_push(queue_t *queue, int data);//入队
extern int queue_pop(queue_t *queue);//出队
extern int queue_size(queue_t *queue);//获取有效数据个数
#endif
