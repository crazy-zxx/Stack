#include <stdio.h>
#include <stdlib.h>
#include "commonDefine.h"
/*--------------------------------- 顺序栈的动态数组实现 ---------------------------------*/

/*-------------- 栈的初始化 ----------------*/
Status InitStack(SqStack &S) {
    //分配存储空间
    S.base = (SElemType *) malloc(sizeof(SElemType) * STACK_INIT_SIZE);
    //容量
    S.stacksize = STACK_INIT_SIZE;
    //栈顶指针，初始化指在第一个元素的位置（push：先存入再后移；pop：先前移再取出）
    S.top = S.base;

    return OK;
}

/*-------------- 取栈顶元素值 ----------------*/
Status GetTop(SqStack S, SElemType &e) {
    //判断栈空
    if (S.top == S.base) {
        return ERROR;
    }
    //栈顶值
    e = *(S.top - 1);

    return OK;
}

/*-------------- 入栈 ----------------*/
Status Push(SqStack &S, SElemType e) {
    //判断栈满扩容
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType *) realloc(S.base, sizeof(SElemType) * (S.stacksize + STACKINCREMENT));
        if (!S.base) {
            exit(OVERFLOW);
        }
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    //入栈
    *S.top++ = e;

    return OK;
}

/*-------------- 出栈 ----------------*/
Status Pop(SqStack &S, SElemType &e) {
    //判断栈空
    if (S.top == S.base) {
        return ERROR;
    }
    //出栈
    e = *(--S.top);

    return OK;
}

/*-------------- 栈空判断 ----------------*/
Status StackEmpty(SqStack S) {
    if (S.top == S.base) {
        return TRUE;
    } else {
        return FALSE;
    }

    return OK;
}

/*-------------- 栈的长度 ----------------*/
int StackLength(SqStack S) {
    int count = 0;
    while (S.top != S.base) {
        S.top--;
        count++;
    }

    return count;
}

/*-------------- 清空栈 ----------------*/
Status ClearStack(SqStack &S) {
    S.top = S.base;

    return OK;
}

/*-------------- 销毁栈 ----------------*/
Status DestroyStack(SqStack &S) {
    free(S.base);
    S.top = S.base = NULL;
    S.stacksize = 0;

    return OK;
}

/*-------------- 打印栈(从栈顶到栈底) ----------------*/
void printStack(SqStack S) {
    if (S.top == S.base) {
        printf("空栈！\n");
        return;
    }
    while (S.top != S.base) {
        printf("%d ", *(--S.top));
    }
    printf("\n");
}

/*-------------------------------------------------------------------------------------*/

/*--------------------------------- 顺序栈的静态数组实现 ---------------------------------*/
//一般在实现某具体函数时，若内部需要使用栈可以通过此类简易的方式实现
void function() {
    //简易顺序栈，定义及初始化
    SElemType stacks[STACK_INIT_SIZE];
    //栈顶指针，初始化指在第一个元素的位置（push：先存入再后移；pop：先前移再取出）
    int top = 0;

    //判空
    if (!top) {  //空
        //...
    }

    SElemType e = 10;
    //入栈
    stacks[top++] = e;

    //出栈
    e = stacks[--top];

    //取栈顶
    e = stacks[top - 1];

    //清空栈
    top=0;
}

/*-------------------------------------------------------------------------------------*/

/*------------------------------------ 链栈的实现 ---------------------------------------*/
Status InitStack(LinkStack &S) {
    S.top=NULL;

    return OK;
}

/*-------------- 取栈顶元素值 ----------------*/
Status GetTop(LinkStack S, SElemType &e) {
    //判断栈空
    if (!S.top) {
        return ERROR;
    }
    //栈顶值
    e = S.top->data;

    return OK;
}

/*-------------- 入栈 ----------------*/
Status Push(LinkStack &S, SElemType e) {

    //入栈,头插法
    Stack t=(Stack)malloc(sizeof(SNode));
    t->data=e;
    t->next=S.top;
    S.top=t;

    return OK;
}

/*-------------- 出栈 ----------------*/
Status Pop(LinkStack &S, SElemType &e) {
    //判断栈空
    if (!S.top) {
        return ERROR;
    }
    //出栈
    e=S.top->data;
    Stack t=S.top;
    S.top=S.top->next;
    free(t);

    return OK;
}

/*-------------- 栈空判断 ----------------*/
Status StackEmpty(LinkStack S) {
    if (!S.top) {
        return TRUE;
    } else {
        return FALSE;
    }

    return OK;
}

/*-------------- 栈的长度 ----------------*/
int StackLength(LinkStack S) {
    int count = 0;
    Stack t=S.top;
    while (t) {
        t=t->next;
        count++;
    }

    return count;
}


/*-------------- 销毁栈 ----------------*/
Status DestroyStack(LinkStack &S) {
    while (S.top){
        Stack t=S.top;
        S.top=S.top->next;
        free(t);
    }

    return OK;
}

/*-------------- 打印栈(从栈顶到栈底) ----------------*/
void printStack(LinkStack S) {
    if (!S.top) {
        printf("空栈！\n");
        return;
    }
    Stack t=S.top;
    while (t) {
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}

/*-------------------------------------------------------------------------------------*/



int main() {
//
//    SqStack S1;
//    InitStack(S1);
//    printStack(S1);
//    SElemType se = 1000;
//    Push(S1, se);
//    Push(S1, 10);
//    printStack(S1);
//    Pop(S1, se);
//    printf("se:%d\n", se);
//    GetTop(S1, se);
//    printf("se:%d\n", se);
//    printf("length:%d\n", StackLength(S1));
//    printf("empty:%d\n", StackEmpty(S1));
//    ClearStack(S1);
//    printf("empty:%d\n", StackEmpty(S1));
//    DestroyStack(S1);

    LinkStack S2;
    InitStack(S2);
    printStack(S2);
    SElemType se2 = 1000;
    Push(S2, se2);
    Push(S2, 10);
    printStack(S2);
    Pop(S2, se2);
    printf("se2:%d\n", se2);
    GetTop(S2, se2);
    printf("se2:%d\n", se2);
    printf("length:%d\n", StackLength(S2));
    printf("empty:%d\n", StackEmpty(S2));
    DestroyStack(S2);
    printf("empty:%d\n", StackEmpty(S2));


    return 0;
}
