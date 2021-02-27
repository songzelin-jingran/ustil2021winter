#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    node* next;
} Node, * LinkQueueNode;

typedef struct
{
    LinkQueueNode front; //队头指针
    LinkQueueNode rear;  //队尾指针
} LinkQueue;

int GetLength_LinkQueue(LinkQueue* Q)//求链队列的长度
{
    int count = 0;
    LinkQueueNode p = Q->front->next;//指向存放数据的第一个结点
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool InitQueue(LinkQueue* Q)//链队列初始化
{
    Q->front = (LinkQueueNode)malloc(sizeof(Node));
    if (Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return true;
    }
    else
        return false;//溢出
}

bool EnterQueue(LinkQueue* Q, int x)//入队，将数据元素x插入到队列Q中
{
    LinkQueueNode NewNode;
    NewNode = (LinkQueueNode)malloc(sizeof(Node));
    if (NewNode != NULL)
    {
        NewNode->data = x;
        NewNode->next = NULL;
        Q->rear->next = NewNode;
        Q->rear = NewNode;
    }
    else
        return false;//溢出
}

bool DeleteQueue(LinkQueue* Q, int* x)//出队，将队列Q的队头元素出队并保存到x所指的存储空间中
{
    LinkQueueNode p;
    if (Q->front == Q->rear)//表示队列已空
        return false;
    p = Q->front->next;
    Q->front->next = p->next;//队头元素p出队
    if (Q->rear == p)//如果队中只有一个元素p，则p出队后成为空队
        Q->rear = Q->front;
    *x = p->data;
    free(p);//释放存储空间
    return true;
}

bool IsEmpty_LinkQueue(LinkQueue* Q)//判断链队列是否为空
{
    return Q->front == Q->rear;

}

void Destroy_LinkQueue(LinkQueue* Q)//销毁链队列
{
    while (Q->front)//从头结点开始释放链队列中所有的结点
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

void Clear_LinkQueue(LinkQueue* Q)//清空链队列
{
    Destroy_LinkQueue(Q);
    InitQueue(Q);
    printf("队列已清空\n");
}

void GetHead_LinkQueue(LinkQueue* Q, int* x)//取得链队列的头部元素
{
    if (IsEmpty_LinkQueue(Q))
        printf("链队列为空!\n");
    else
        *x = Q->front->next->data;
}

void GetRear_LinkQueue(LinkQueue* Q, int* x)//取得链队尾的头部元素
{
    if (IsEmpty_LinkQueue(Q))
        printf("链队列为空!\n");
    else
        *x = Q->rear->data;
}

void Print_LinkQueue(LinkQueue* Q)//输出链队列
{
    LinkQueueNode p = Q->front->next;//p指向头结点的下一个结点，即存放数据的第一个结点
    if (IsEmpty_LinkQueue(Q))
        printf("链队列为空!\n");
    else
    {
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    int x;
    int* a = &x;
    LinkQueue Q;
    LinkQueue* q = &Q;
    InitQueue(q);
    if (IsEmpty_LinkQueue(q))
        printf("该队列为空\n");
    for (int i = 1; i <= 10; i++)
        EnterQueue(q, i);
    printf("队列中有%d个元素\n", GetLength_LinkQueue(q));
    Print_LinkQueue(q);
    GetHead_LinkQueue(q, a);
    printf("队头元素为%d\n", x);
    GetRear_LinkQueue(q, a);
    printf("队尾元素为%d\n", x);
    for (int i = 1; i <= 10; i++)
    {
        DeleteQueue(q, a);
        printf("删除元素%d ", x);
    }
    printf("\n");
    Clear_LinkQueue(q);
    if (IsEmpty_LinkQueue(q))
        printf("该队列为空\n");
    return 0;
}
