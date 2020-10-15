//
// Created by xylx on 2020/10/14.
//

#ifndef SQLIST_COMMONDEFINE_H
#define SQLIST_COMMONDEFINE_H


/* ----------- 常用返回值预定义 --------------*/
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
/*-----------------------------------------*/

//元素类型
typedef int SElemType;

/* ----------- 动态顺序栈结构定义 ---------------*/
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct sqSNode{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
/*-----------------------------------------*/


/* ----------- 链栈结构定义 ---------------*/
//单链表节点
typedef struct lSNode {
    SElemType data;
    struct lSNode *next;
}LSNode, *Stack;
/*-----------------------------------------*/



#endif //SQLIST_COMMONDEFINE_H
