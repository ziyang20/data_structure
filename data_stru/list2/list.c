//list.c:双链表的各种定义
#include "list.h"
//定义初始化函数
void list_init(list_t *list) {
    //1.头指向尾
    list->head.next = &list->tail;
    //2.尾指向头
    list->tail.prev = &list->head;
    list->head.data = 0;
    list->tail.data = 0;
    list->head.prev = NULL;
    list->tail.next = NULL;
}
//定义判断链表是否为空
int list_empty(list_t *list) {
    return list->head.next == &list->tail;//空返回1,否则返回0
}
//定义获取节点个数的函数
int list_size(list_t *list) {
    int count = 0; //记录节点个数
    for(node_t *pnode = &list->head; pnode != &list->tail; pnode=pnode->next) {
        node_t *pfirst = pnode;
        node_t *pmid = pfirst->next;
        node_t *plast = pmid->next;
        if(pmid != &list->tail) //pmid不等于尾节点,那么pmid指向的节点必然是有效节点
            count++; //更新计数
    }
    return count; //返回节点个数
}
//定义创建新节点函数
static node_t *create_node(int data) {
    node_t *pnew = malloc(sizeof(node_t)); //分配内存
    pnew->data = data;
    pnew->next = NULL;
    pnew->prev = NULL;
    return pnew; //返回新节点的首地址
}
//定义插入新节点函数,将新节点pnew插入到pfirst和pmid中间
static void insert_node(node_t *pfirst, node_t *pmid, node_t *pnew) {
    pfirst->next = pnew;
    pnew->prev = pfirst;
    pnew->next = pmid;
    pmid->prev = pnew;
}
//定义顺序插函数
void list_add(list_t *list, int data) {
    //1.给data创建所在的新节点
    node_t *pnew = create_node(data);
    //2.遍历找到要插入的位置,将新节点插入到pfirst和pmid中间
    for(node_t *pnode = &list->head; pnode != &list->tail; pnode=pnode->next) {
        node_t *pfirst = pnode;
        node_t *pmid = pfirst->next;
        node_t *plast = pmid->next;
        if(pmid->data > pnew->data || pmid == &list->tail/*新节点最大,放到最后一个*/) {
            insert_node(pfirst, pmid, pnew); 
            break;
        }
    }
}
//定义前插函数
void list_add_first(list_t *list, int data) {
    //1.创建新节点
    node_t *pnew = create_node(data);
    //2.造游标
    node_t *pfirst = &list->head; //pfirst指向头节点
    node_t *pmid = pfirst->next; //pmid指向原先的第一个节点
    node_t *plast = pmid->next; //plast指向第二个节点或者尾节点
    //3.将新节点pnew插入到pfirst和pmid中间,也就是插入到头节点和原先第一个节点中间
    insert_node(pfirst, pmid, pnew);
}
//定义后插函数
void list_add_last(list_t *list, int data) {
    //1.创建新节点
    node_t *pnew = create_node(data);
    //2.造游标
    node_t *pfirst = list->tail.prev; //pfirst指向原先最后一个节点
    node_t *pmid = pfirst->next; //pmid指向尾节点
    node_t *plast = pmid->next; //plast指向NULL
    //3.将新节点pnew插入到pfirst和pmid中间,也就是插入到原先最后一个节点和尾节点中间
    insert_node(pfirst, pmid, pnew);
}
//定义删除pmid指向的节点函数
static void del_node(node_t *pfirst, node_t *pmid, node_t *plast) {
    pfirst->next = plast;
    plast->prev = pfirst;
    free(pmid); //释放节点内存
}
//定义删除指定的节点
void list_del(list_t *list, int data) {
    //1.遍历找到要删除的节点,然后让pmid指向要删除的节点
    for(node_t *pnode = &list->head; pnode != &list->tail; pnode=pnode->next) {
        node_t *pfirst = pnode;
        node_t *pmid = pfirst->next;
        node_t *plast = pmid->next;
        if(pmid->data == data && pmid != &list->tail/*尾节点不能删*/) {
            del_node(pfirst, pmid, plast);//删除pmid指向的节点,连接pfirst和plast
            break;        
        }
    }
}
//定义只删除第一个节点
void list_del_first(list_t *list) {
    //1.判断链表是否为空
    if(list_empty(list)) {
        printf("链表空了.\n");
        return;
    }
    //2.造游标
    node_t *pfirst = &list->head; //指向头
    node_t *pmid = pfirst->next; //指向要删除的第一个节点
    node_t *plast = pmid->next; //指向后一个节点或者尾节点
    //3.删除
    del_node(pfirst, pmid, plast);
}
//定义只删除最后一个节点
void list_del_last(list_t *list) {
    //1.判断链表是否为空 
    if(list_empty(list)) {
        printf("链表空了.\n");
        return;
    }
    //2.造游标
    node_t *plast = &list->tail; //plast指向尾节点
    node_t *pmid = plast->prev; //pmid指向要删除的最后一个节点
    node_t *pfirst = pmid->prev; //pfirst指向前一个节点或者head
    //3.删除
    del_node(pfirst, pmid, plast);
}
//定义根据节点编号获取节点数据
int list_get(list_t *list, int index) {
    int count = 0; //记录循环的次数
    for(node_t *pnode = &list->head; pnode != &list->tail; pnode = pnode->next) {
        node_t *pfirst = pnode;
        node_t *pmid = pfirst->next;
        node_t *plast = pmid->next;
        if(index == count && pmid != &list->tail)
            return pmid->data;
        count++;
    }
}
//定义清空双链表所有节点的函数
void list_deinit(list_t *list) {
    while(list->head.next != &list->tail) { //说明链表中还有节点
        node_t *pfirst = &list->head; //pfirst永远指向头结点
        node_t *pmid = pfirst->next; //pmid指向要清除的第一个节点
        node_t *plast = pmid->next; //plast指向第二个节点
        del_node(pfirst, pmid, plast);
    }
}









