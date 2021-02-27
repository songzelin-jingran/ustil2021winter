#include<stdio.h>
#define STACK_SIZE 20 //定义栈的空间大小
typedef struct Stack
{
	int dates[STACK_SIZE];  //方便数据移动
	int top; //栈顶部标识，空栈为-1
}stack;
//初始化栈
void Init(stack* s)
{
	s->top = -1;
}
//清空栈
void empty(stack* s)
{
	s->top = -1;
}
//判断栈空
int isempty(stack* s)
{
	return(s->top == -1) ? 1 : 0;
}
//判断栈满
int isfull(stack* s)
{
	return(s->top == STACK_SIZE - 1) ? 1 : 0;
}
//入栈
int push(stack* s, int value)
{
	if (isfull(s))//先判断是否已满
	{
		return 0;
	}
	s->dates[++s->top] = value;
	return 1;
}
//出栈
int pop(stack* s, int* retvalue)
{
	//先检查是否为空
	if (isempty(s))
	{
		return 0;
	}
	*retvalue = s->dates[s->top--]; //指针变量存储数据地址
	return 1;
}
//读栈顶操作
int getTop(stack* s, int* retvalue)
{
	//先检查是否为空
	if (isempty(s))
	{
		return 0;
	}
	*retvalue = s->dates[s->top];
	return 1;
}
//输出栈中内容
void printStack(stack* s)
{
	int i = 0;
	if (isempty(s))
	{
		printf("当前栈空\n");
		return;
	}
	else
	{
		printf("当前栈中内容为：\n");
		for (i = s->top; i > -1; i--)
		{
			printf("[%d]%d\n", i, s->dates[i]);
		}
	}
	printf("end\n");
}
void change(stack* s, int a1, int a2)
{
	int i;
	for (i = s->top; i > -1; i--)
	{
		if (s->dates[i] == a1)
		{
			s->dates[i] = a2;
			break;
		}

	}
}
int main()
{
	int i = 0, retvalue;
	stack s;
	//初始化
	Init(&s);
	//入栈
	for (i = 0; i < 10; i++)
		push(&s, i * 10);//写数据
	printStack(&s);//查询
	//出栈
	for (i = 0; i < 4; i++)
		pop(&s, &retvalue);
	printStack(&s);
	//修改
	change(&s, 40, 100);
	printStack(&s);
	return;

}
