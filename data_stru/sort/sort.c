//sort.c
#include "sort.h"
//定义冒泡排序函数
void bubble_sort(int data[], int size) {
    int i, j;
    for(i = 0; i < size-1; i++) { //排序的趟次
        int ordered = 1;//判断是否发生数据交换,如果交换了ordered=0,如果没有交换ordered=1
        for(j = 0; j < size-1-i; j++) { //每趟比较的次数
            if(data[j+1] < data[j]) { //交换数据
                int swap = data[j];
                data[j] = data[j+1];
                data[j+1] = swap;
                ordered = 0; //标记数据发生了交换
            }
        }
        //每趟排序之后判断这趟排序是否发生了数据交换,如果没有交换数据则排序完成
        if(ordered)
            break;
    }
}
//定义插入排序算法函数:10 30 20 15 5
void insert_sort(int data[], int size) {
    int i;
    for(i = 1; i < size; i++) { //取数的次数,第一个数据本身有序
        int inserted = data[i]; //暂存被插入的数据
        int j;
        //从后往前扫描找到对应的位置
        for(j = i; j > 0 && inserted < data[j-1]; --j)
            data[j] = data[j-1];//交换位置
        //如果被插入的数据比前面的有序数列中的任何一个数据都大,则不用重复插入
        //1 2 3 4 5
        //5
        if(j!=i)
            data[j] = inserted; //将被插入的数据插入到对应的位置即可
    }
}
//定义选择排序算法函数
void select_sort(int data[], int size) {
    int i;
    for(i = 0; i < size - 1; i++) {//找最小数的趟次,最后一个数据本身有序的
        int min = i; //假设无序数列中的第一个数据最小,min记录最小数对应的下标
        int j;
        for(j = i + 1; j < size; j++) //找最小数
            if(data[j] < data[min])
                min = j; //更新记录最小数对应的下标,用min记录
        if(min != i) { //如果不是第一个最小,那么则交换
            int swap = data[i];
            data[i] = data[min];
            data[min] = swap;
        }
    }
}
//定义快速排序算法函数
void quick_sort(int data[], int left, int right) {
    int p = (left+right)/2; //定义基准值对应的下标,可以随意指定 
    int i = left; //left=0,左边界 
    int j = right; //right=size-1,右边界
    int pivot = data[p]; //暂存基准值
    while(i < j) { //进行一次分组,i=j停止分组
        //i不做i++运算的两种情况:i=p重合或者i对应的值大于基准值
        for(; !(i>=p || pivot < data[i]); i++);
        //此种情况就是i对应的值大于基准值而退出了上面的for循环,而不是i=p重合的情况
        if(i < p) {
            data[p] = data[i]; //将i对应的值挪到p的位置
            p = i; //将p调整到i的位置
        }
        //j不做j--运算的两种情况:j=p重合或者j对应的值小于基准值
        for(; !(j<=p || pivot > data[j]); j--);
        //此种情况就是j对应的值小于基准值而退出了上面的for循环,而不是j=p重合的情况
        if(j > p) {
            data[p] = data[j]; //将j对应的值挪到p的位置
            p = j;//调整p到j的位置
        }
    }
    data[p] = pivot; //一次分组结束将基准值挪到p的位置
    if(p - left > 1)//基准值左边的数据个数大于等于2个继续分组直到剩余1个或者没有无需分组
        quick_sort(data, left, p-1);//对左边继续分区,左边界还是0,右边界是p-1,不包含p
    if(right - p > 1)//基准值右边的数据个数大于等于2个继续分组直到剩余1个或者没有无需分组
        quick_sort(data, p+1, right);//对右边继续分组,右边界还是right,左边界是p+1,不包含p
}




















