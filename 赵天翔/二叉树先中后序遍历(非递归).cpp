#include <iostream>
#include <stack>
using namespace std;
//树的结构体定义
typedef struct BiTree
{
    char data;
    struct BiTree* lchild, * rchild;
}BiNode, * BTree;

//递归创建二叉链表
void CreatBiTree(BTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiTree;
        T->data = ch;//先序创建
        CreatBiTree(T->lchild);
        //T->data=ch;//中序创建
        CreatBiTree(T->rchild);
        //T->data=ch;//后序创建
    }
}

//非递归方法
void PreOder(BTree root) {
    stack<BTree> Btstack;
    BTree T = root;
    while (T || !Btstack.empty()) {
        while (T) {
            Btstack.push(T);
            printf("%c ", T->data);
            T = T->lchild;
        }
        T = Btstack.top();
        Btstack.pop();
        T = T->rchild;
    }
}

void InOder(BTree root) {
    stack<BTree> Btstack;
    BTree T = root;
    while (T || !Btstack.empty()) {
        while (T) {
            Btstack.push(T);
            T = T->lchild;
        }
        T = Btstack.top();
        Btstack.pop();
        printf("%c ", T->data);;
        T = T->rchild;
    }
}

void PostOrder(BTree root) {
    stack<BTree> Btstack;
    BTree top, last = NULL;
    BTree T = root;
    while (T || !Btstack.empty()) {
        while (T) {
            Btstack.push(T);
            T = T->lchild;
        }
        top = Btstack.top();
        if (top->rchild == NULL || top->rchild == last) {
            printf("%c ", top->data);
            Btstack.pop();
            last = top;
        }
        else {
            T = top->rchild;
        }
    }
}

int main() {
    BTree A;
    cout << "请按先序遍历输入数据：" << endl;
    CreatBiTree(A);
    cout << endl;
    cout << "非递归先序遍历输出结果：" << endl;
    PreOder(A);
    cout << endl;
    cout << "非递归中序遍历输出结果：" << endl;
    InOder(A);
    cout << endl;
    cout << "非递归后序遍历输出结果：" << endl;
    PostOrder(A);
    cout << endl;
    return 0;
}
