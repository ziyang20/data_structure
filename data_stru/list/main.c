//main.c:单链表测试
#include "list.h"
int main(void) {
    //1.创建单链表
    list_t list;
    //2.初始化单链表
    list_init(&list);
    //3.各种插入和遍历
    list_add(&list, 10);
    list_add(&list, 20);
    list_add(&list, 30);
    list_travel(&list);
    list_add_first(&list, 5);
    list_add_first(&list, 3);
    list_travel(&list);
    list_add_last(&list, 40);
    list_add_last(&list, 50);
    list_travel(&list);
    //4.删除节点
    list_del(&list, 20);
    list_travel(&list);
    //5.释放整个链表
    list_deinit(&list);
    return 0;
}
