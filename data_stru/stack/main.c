//main.c:测试
#include "stack.h" //声明
int main(void) {  
    //定义栈变量
    stack_t stack;//arr, cap, top 
    //初始化
    //通过stack的地址来访问stack的arr,cap,top 
    //stack_t* stack = &stack;
    stack_init(&stack, 10);//指定容量是10
    int data = 1;
    while(!stack_full(&stack))//循环压栈
        stack_push(&stack, data++);
    printf("有效个数是:%d\n", stack_size(&stack));
    while(!stack_empty(&stack))//循环出栈
        printf("%d ", stack_pop(&stack));
    printf("\n");
    printf("有效个数是:%d\n", stack_size(&stack));
    stack_deinit(&stack); //释放内存
    return 0;
}
