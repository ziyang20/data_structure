//main.c:双链表测试
#include "list.h"
int main(void) {
    list_t list;//定义
    list_init(&list);//初始化
    //各种插入
    list_add_first(&list, 50);
    list_add_first(&list, 20);
    list_add_last(&list, 70);//20 50 70 
    list_add_last(&list, 100);//20 50 70 100
    list_add(&list, 80);
    list_add(&list, 30);
    list_add(&list, 40);
    list_add(&list, 60);
    list_add(&list, 90);
    list_add(&list, 10);
    int size = list_size(&list);//获取节点个数
    for(int i = 0; i < size; i++)
        printf("%d ", list_get(&list, i));//遍历
    printf("\n");
    list_del_first(&list);
    list_del_last(&list);
    list_del(&list, 50);
    size = list_size(&list);//获取节点个数
    for(int i = 0; i < size; i++)
        printf("%d ", list_get(&list, i));//遍历
    printf("\n");
    list_deinit(&list); //清除链表
    return 0;
}
