//main.c:测试
#include "queue.h"
int main(void) {
    queue_t queue; //定义队列
    queue_init(&queue, 4);//初始化队列,容量为4个数据
    for(int i = 10; i <= 40; i += 10) 
        if(!queue_full(&queue))
            queue_push(&queue, i); //入队:10 20 30 40
    printf("有效数据个数:%d\n", queue_size(&queue));
    for(int i = 0; i < 2; i++)
        if(!queue_empty(&queue))
            printf("%d ", queue_pop(&queue)); //出10 20
    printf("\n");
    printf("有效数据个数:%d\n", queue_size(&queue));
    for(int i = 50; i <= 60; i += 10) 
        if(!queue_full(&queue))
            queue_push(&queue, i); //入队:50 60 30 40
    printf("有效数据个数:%d\n", queue_size(&queue));
    while(!queue_empty(&queue)) //整体出队:30 40 50 60
        printf("%d ", queue_pop(&queue));
    printf("\n");
    queue_deinit(&queue); //释放内存
    return 0;
}
