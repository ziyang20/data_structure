//main.c
#include "find.h"
#include "sort.h"
int main(void) {
    int data[] = {9,0,7,2,5,4,1,6,3,8};
    int size = sizeof(data)/sizeof(data[0]);
    int key = 7; //目标
    int index = -1; //保存下标
    index = line_find(data, size, key);
    if(index == -1) {
        printf("没有找到.\n");
        return -1;
    }
    printf("找到:data[%d]=%d\n", 
                index, data[index]);
    //先快速排序
    quick_sort(data, 0, size-1);
    index = half_find(data, size, key);
    if(index == -1) {
        printf("没有找到.\n");
        return -1;
    }
    printf("找到:data[%d]=%d\n", 
                index, data[index]);
    return 0;
}
