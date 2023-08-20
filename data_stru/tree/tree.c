//tree.c:有序二叉树各种定义
#include "tree.h"

//定义遍历的递归函数
static void travel(node_t *proot) {

    //中序遍历
    if(proot != NULL) {
        travel(proot->left); //打印左节点
        printf("%d ", proot->data); //打印节点数据
        travel(proot->right); //打印右节点
        return;
    }
    /*
    //先序遍历
    if(proot != NULL) {
        printf("%d ", proot->data); //打印节点数据
        travel(proot->left); //打印左节点
        travel(proot->right); //打印右节点
        return;
    }
    //后序遍历
    if(proot != NULL) {
        travel(proot->left); //打印左节点
        travel(proot->right); //打印右节点
        printf("%d ", proot->data); //打印节点数据
        return;
    }
    */
    return;
};
//定义有序二叉树遍历函数
void tree_travel(tree_t *tree) {
    //调用递归函数从根节点开始遍历
    travel(tree->root);
    printf("\n");
}

//定义清空节点的递归函数
void clear(node_t **pproot) {
    if(*pproot != NULL) {
        clear(&(*pproot)->left); //清空左子树
        clear(&(*pproot)->right); //清空左子树
        free(*pproot); //释放节点内存
        *pproot = NULL; //修改指向释放节点的父节点指向NULL,否则就是野指针
        return;
    }
    return;
}
//定义清空二叉树所有节点函数
void tree_clear(tree_t *tree) {
    //调用递归函数从根节点开始清空
    clear(&tree->root);
}
//定义分配新节点的内存函数
static node_t *create_node(int data) {
    node_t *pnew = malloc(sizeof(node_t));
    pnew->data = data;
    pnew->left = NULL;
    pnew->right = NULL;
    return pnew;
}

//定义插入新节点的递归函数
static void insert(node_t **pproot, node_t *pnew) {
    if(*pproot == NULL) {
        *pproot = pnew; //插入新节点
        return;
    }
    if((*pproot)->data > pnew->data) {
        insert(&(*pproot)->left, pnew); //将新节点插入插入到左子树
        return;
    } else {
        insert(&(*pproot)->right, pnew); //将新节点插入插入到右子树
        return;
    }
    return;
}
//定义插入新节点的函数
void tree_insert(tree_t *tree, int data) {
    //1.创建新节点
    node_t *pnew = create_node(data);
    //2.调用递归函数插入新节点
    insert(&tree->root, pnew);
    //3.更新计数
    tree->cnt++;
}

//定义查找节点的递归函数
static node_t **find(node_t **pproot, int data) {
    //1.停止查找
    if(*pproot == NULL)
        return pproot; //没有找到
    //2.比较
    if((*pproot)->data == data)
        return pproot; //找到了
    else if(data < (*pproot)->data)
        return find(&(*pproot)->left, data); //左边找
    else
        return find(&(*pproot)->right, data); //右边找
}
//定义查找节点函数
static node_t **find_node(tree_t *tree, int data) {
    //调用递归函数从根节点开始查找要删除的节点
    return find(&(tree)->root, data);
}
//定义删除指定的节点函数
void tree_del(tree_t *tree, int data) {
    //1.找节点
    node_t **ppnode = find_node(tree, data);
    if(*ppnode == NULL) {
        printf("没有找到节点.\n");
        return;
    }
    //2.找新爹:如果要删除的节点的左子树不为空,将左子树插入到右子树上
    if((*ppnode)->left != NULL)
        insert(&(*ppnode)->right, (*ppnode)->left);
    //3.提一级:将要删除的节点的父节点的左子树指向要删除的节点的右子树上
    //(*ppnode):就是50的L
    //(*ppnode)->right:删除的节点的右子树
    node_t *ptmp = *ppnode; //临时备份要删除的节点,将来用于free,ptmp指向20
    (*ppnode) = (*ppnode)->right; //50的L指向40
    free(ptmp); //释放20
    tree->cnt--; //更新计数
}
//定义修改节点值的函数
void tree_modify(tree_t *tree, int old_data, int new_data) {
    //1.先删除节点
    tree_del(tree, old_data);
    //2.插入新节点
    tree_insert(tree, new_data);
}


