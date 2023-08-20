//sort.h
#ifndef __SORT_H
#define __SORT_H
#include <stdio.h>
extern void bubble_sort(int data[], int size);//冒泡排序算法函数声明
extern void insert_sort(int data[], int size); //插入排序
extern void select_sort(int data[], int size); //选择排序
extern void quick_sort(int data[], int left, int right); //快排
#endif
