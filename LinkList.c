#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype;

typedef struct Node
{
    datatype data;
    struct Node *next;
} Linklist;

// 展示节点
void display(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// 单链表的初始化
void InitList(Linklist *L)
{
}

// 创建单链表
Linklist CreateList(datatype a[], int n)
{
    Linklist *s;

    Linklist *head = (Linklist *)malloc(sizeof(Linklist));
    head->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (Linklist *)malloc(sizeof(Linklist));
        s->data = a[i];
        s->next = head->next;
        head->next = s;
    }
    return *head;
}

// 按位查找的函数
int Get(Linklist *L, int i, datatype e)
{
    int j = 0;
    Linklist *p = L;
    if (i < 0)
        return -1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return -1;
    else
        e = p->data;
    return 1;
}

// 单链表的按值查找
int Locate(Linklist *L, int i, datatype e)
{
    Linklist *p = L->next;
    int j = 1;
    while (p && e == p->data)
    {
        p = p->next;
        j++;
    }
    if (!p)
        return -1;
    else
        return (j);
}

// 单链表的插入
int Insert(Linklist *L, int i, datatype e)
{
    Linklist *p = L;
    Linklist *s;
    int j = 0;
    if (i < 0)
        return -1;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
        return -1;
    else
    {
        s = (Linklist *)malloc(sizeof(Linklist));
        s->data = e;
        s = p->next;
        p->next = s;
        return 1;
    }
}
// 删除单链表的某个元素
int Delete(Linklist *L, int i, datatype e)
{
    Linklist *p = L;
    Linklist *q;
    int j = 0;
    while (p && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (!p || !p->next)
    {
        printf("没有该结点");
        return -1;
    }
    else
    {
        q = p->next;
        e = q->data;
        p->next = q->next;
        free(q);
        return 1;
    }
}

int main()
{
    datatype a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    Linklist CreateList(a, n);

    Linklist L;

    printf("输出一个单链表\n请输入元素");
}
