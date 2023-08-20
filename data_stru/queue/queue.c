//queue.c:队列定义
#include "queue.h"
//定义初始化队列函数
void queue_init(queue_t *queue, int cap) {
    queue->arr = malloc(sizeof(int)*cap);//分配内存
    queue->cap = cap;
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
}
//定义释放内存函数
void queue_deinit(queue_t *queue) {
    free(queue->arr);
    queue->cap = 0;
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
}
//定义判断满的函数
int queue_full(queue_t *queue) {
    return queue->size >= queue->cap; //满返回1,否则返回0
}
//定义判断空的函数
int queue_empty(queue_t *queue) {
    return !queue->size; //空返回1,否则返回0
}
//定义判断入队和出队函数
void queue_push(queue_t *queue, int data) {
    if(queue->rear >= queue->cap)
        queue->rear = 0; //构造循环队列
    queue->arr[queue->rear++] = data;
    queue->size++; //更新计数
}
int queue_pop(queue_t *queue) {
    if(queue->front >= queue->cap)
        queue->front = 0;//构造循环队列
    queue->size--; //更新计数
    return queue->arr[queue->front++];
}
//定义获取有效数据个数函数
int queue_size(queue_t *queue) {
    return queue->size;
}















