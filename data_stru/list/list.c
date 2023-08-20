//list.c:单链表的定义
#include "list.h"
//定义分配新节点内存函数
static node_t *create_node(int data) {
    node_t *pnew = malloc(sizeof(node_t)); //分配节点内存
    pnew->data = data; //初始化节点数据
    pnew->next = NULL;
    return pnew; //返回新节点的首地址
}
//定义单链表的初始化函数
void list_init(list_t *list) {
    //1.给头节点分配内存
    list->head = create_node(0);
    //2.给尾节点分配内存
    list->tail = create_node(0);
    //3.头指向尾
    list->head->next = list->tail;
    list->tail->next = NULL;
}
//定义单链表的遍历函数
void list_travel(list_t *list) {
    for(node_t *pnode = list->head; pnode != list->tail; pnode = pnode->next) {
        //1.定义三个游标
        node_t *pfirst = pnode;
        node_t *pmid = pfirst->next;
        node_t *plast = pmid->next;
        //2.判断pmid是否是有效节点
        if(pmid != list->tail)
            printf("%d ", pmid->data);
    }
    printf("\n");
}
//定义顺序新节点插函数
void list_add(list_t *list, int data) {
    //1.创建新节点
    node_t *pnew = create_node(data);
    //2.遍历找到要插入的位置,让pmid指向后一个节点,pfirst指向前一个节点
    //那么pnew新节点就插入到pfirst和pmid中间即可
    for(node_t *pnode = list->head; pnode != list->tail; pnode = pnode->next) {
        //3.定义三个游标
        node_t *pfirst = pnode;
        node_t *pmid = pfirst->next;
        node_t *plast = pmid->next;
        if(pmid->data >= pnew->data /*新节点小于后一个节点插入*/
                || pmid == list->tail/*新节点比前面的节点数据都大,放在最后一个即可*/) 
        {
            pfirst->next = pnew;
            pnew->next = pmid;
            break;
        }
    }
}
//定义前插函数和后插函数
void list_add_first(list_t *list, int data) {
    //1.创建新节点
    node_t *pnew = create_node(data);
    //2.插入新节点pnew到头结点和原先的第一个节点中间
    node_t *ptmp = list->head->next; //临时备份原先的第一个节点
    list->head->next = pnew;
    pnew->next = ptmp; 
}
void list_add_last(list_t *list, int data) {
    //1.创建新节点
    node_t *pnew = create_node(data);
    //2.遍历找到最后一个节点让pfirst指向最后一个节点,pmid指向尾节点
    for(node_t *pnode = list->head; pnode != list->tail; pnode = pnode->next) {
        //3.定义三个游标
        node_t *pfirst = pnode;
        node_t *pmid = pfirst->next;
        node_t *plast = pmid->next;
        if(pmid == list->tail) { //如果pmid指向了尾节点,那么pfirst肯定指向原先的最后一个节点
            pfirst->next = pnew;
            pnew->next = pmid;
            break;
        }
    }
}
//定义删除指定数字所在的节点函数
void list_del(list_t *list, int data) {
    //1.遍历找到要删除的节点,然后让pmid指向要删除的节点,那么pfirst指向前一个节点
    //plast指向后一个节点
    for(node_t *pnode = list->head; pnode != list->tail; pnode = pnode->next) {
        //2.定义三个游标
        node_t *pfirst = pnode;
        node_t *pmid = pfirst->next;
        node_t *plast = pmid->next;
        if(pmid->data == data && pmid != list->tail/*不能删除尾节点*/) {
            pfirst->next = plast;//让前一个节点pfirst指向后一个节点plast即可
            free(pmid); //释放内存
            break;
        }
    } 
}
//定义释放链表所有节点的函数
void list_deinit(list_t *list) {
    node_t *pnode = list->head;
    while(pnode) {
        node_t *ptmp = pnode->next; //临时备份下一个节点
        free(pnode); //释放pnode指向的节点内存
        pnode = ptmp; //pnode再指向要释放的下一个节点
    }
}

















