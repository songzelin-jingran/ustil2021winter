#include <iostream>
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

//递归方法
void PreOderRecursive(BTree root) {
    if (root) {
        printf("%c ", root->data);
        PreOderRecursive(root->lchild);
        PreOderRecursive(root->rchild);
    }
}

void InOderRecursive(BTree root) {
    if (root) {
        InOderRecursive(root->lchild);
        printf("%c ", root->data);
        InOderRecursive(root->rchild);
    }
}

void PostOderRecursive(BTree root) {
    if (root) {
        PostOderRecursive(root->lchild);
        PostOderRecursive(root->rchild);
        printf("%c ", root->data);
    }
}

int main() {
    BTree A;
    cout << "请按先序遍历输入数据：" ;
    CreatBiTree(A);
    cout << endl;
    cout << "递归先序遍历输出结果：";
    PreOderRecursive(A);
    cout << endl;
    cout << "递归中序遍历输出结果：" ;
    InOderRecursive(A);
    cout << endl;
    cout << "递归后序遍历输出结果：" ;
    PostOderRecursive(A);
    cout << endl;
    return 0;
}
