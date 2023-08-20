#include "find.h"
//定义线性查找函数
//line_find(data, size, 10);
int line_find(int data[], int size, int key) {
    for(int i = 0; i < size; i++)
        if(data[i] == key)
            return i; //找到并且返回对应的下标
    return -1; //没有找到
}
//定义递归二分查找函数
static int recu_find(int data[], int left, int right, int key) {
    if(left <= right) {
        int mid = (left+right)/2; //折半
        if(key < data[mid]) //左边找
            return recu_find(data, left, mid-1, key);
        else if(key > data[mid]) //右边找
            return recu_find(data, mid+1, right, key);
        else
            return mid; //找到了
    }
    return -1; //没有找到
}
//定义二分查找函数
int half_find(int data[], int size, int key) {
    //递归来实现
    return recu_find(data, 0, size-1, key);
#if 0 //常规方法,不用递归
    int left = 0;
    int right = size-1;
    while(left <= right) {
        int mid = (left+right)/2; //折半
        if(key < data[mid]) //左边找
            right = mid - 1; //重新定义右边界,中间值省略
        else if(key > data[mid]) //右边找
            left = mid + 1; //重新定义左边界,中间值省略
        else
            return mid; //找到了
    }
    return -1; //没有找到
#endif
}
