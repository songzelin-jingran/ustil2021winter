#include <stdio.h>
#include <stack>
//顺序栈结构体定义
#define STACKSIZE 64          //栈的大小
typedef int stackType;
typedef struct _snode
{
    stackType data[STACKSIZE];  //栈中的实际存储数据
    int top;            //栈顶指标，等价于数组下标。
}SeqStack, * pSeqStack;
//创建栈
pSeqStack SeqStackCreat()
{
    pSeqStack node = (pSeqStack)malloc(sizeof(SeqStack));
    if (NULL == node)
    {
        perror("malloc err");
        return NULL;
    }
    memset((void*)(node->data), 0, STACKSIZE);
    node->top = -1;
    return node;

}
//判断栈是否满
int SeqStackisFull(pSeqStack S)
{
    if (S->top > STACKSIZE)
        return 1;
    else
        return 0;
}
//入栈
int SeqStackPush(pSeqStack S, stackType data)
{
    if (S->top > STACKSIZE)
    {
        printf("SeqStack is Full\n");
        return -1;
    }
    S->top++;
    S->data[S->top] = data;

    return 0;
}
//出栈
int SeqStackPop(pSeqStack S, stackType* data)
{
    if (S->top < 0)
    {
        printf("SeqStack is Empty\n");
        return -1;
    }
    *data = S->data[S->top];
    S->top--;

    return 0;
}
//删除栈
int SeqStackFree(pSeqStack S)
{
    free(S);
    return 0;
}
int printSeqStack(pSeqStack S)
{
    int i = 0;
    for (i = 0; i <= S->top; i++)
    {

        printf("%4d ", S->data[i]);
    }
    printf("\r\n");
    return i;
}

int main()
{
    //顺序栈
    pSeqStack s_Stack = NULL;
    int m_data = 0;
    s_Stack = SeqStackCreat();

    for (int i = 0; i < 20; i++)
    {
        SeqStackPush(s_Stack, i + 60);
    }
    printSeqStack(s_Stack);

    for (int i = 0; i < 20; i++)
    {
        SeqStackPop(s_Stack, &m_data);
        printf("Pop:%d\r\n", m_data);
    }
    SeqStackFree(s_Stack);
    return 0;
}
