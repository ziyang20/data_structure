//stack.h:栈的各种声明
#ifndef __STACK_H
#define __STACK_H
//包含公共的头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述栈的属性的结构体
typedef struct stack {
    int *arr; //首地址
    int cap; //容量
    int top; //记录栈顶位置
}stack_t;
//stack_t stack;//是否分配了内存 
//声明栈的操作函数 
extern void stack_init(stack_t *stack, int cap); //初始化栈
extern void stack_deinit(stack_t *stack);//释放栈内存
extern int stack_full(stack_t *stack);//判断栈是否满
extern int stack_empty(stack_t *stack);//判断栈是否空
extern void stack_push(stack_t *stack, int data); //压栈
extern int stack_pop(stack_t *stack); //出栈
extern int stack_size(stack_t *stack);//获取栈中有效数据个数
#endif
