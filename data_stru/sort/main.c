//main.c
#include "sort.h"
int main(void) {
    int data[] = {9,0,7,2,5,4,1,6,3,8};
    int size = sizeof(data)/sizeof(data[0]);
    bubble_sort(data, size);//冒泡排序
    //insert_sort(data, size);//插入排序
    //select_sort(data, size);
    //quick_sort(data, 0, size-1);
    for(int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
    return 0;
}
