//stack.c:栈的各种定义
#include "stack.h"
//定义栈的初始化函数 
void stack_init(stack_t *stack, int cap) {
    stack->arr = malloc(sizeof(int)*cap);//给栈分配内存
    stack->cap = cap; //初始化容量
    stack->top = 0; //空栈,一开始没有数据 
}
//定义栈内存释放函数
void stack_deinit(stack_t *stack) {
    free(stack->arr);//释放栈内存
    stack->cap = 0;
    stack->top = 0;
}
//定义判断栈空和满的函数
int stack_full(stack_t *stack) {
    return stack->top == stack->cap; //满返回1,否则返回0
}
int stack_empty(stack_t *stack) {
    return stack->top == 0;//空返回1,否则返回0
}
//定义压栈函数
void stack_push(stack_t *stack, int data) {
    stack->arr[stack->top] = data;
    stack->top++;
}
//定义出栈函数
int stack_pop(stack_t *stack) {
    return stack->arr[--stack->top];
}
//定义获取栈有效数据个数函数
int stack_size(stack_t *stack) {
    return stack->top;
}
