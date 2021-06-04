/*
 * @Author: 许劲淇 
 * @Date: 2020-06-03 08:56:30 
 * @Last Modified by: 许劲淇
 * @Last Modified time: 2020-06-03 09:22:26
 */
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} * LinkedList;

void SelectSort(LinkedList &L);
LinkedList SelectMinNode(LinkedList &q);

int main()
{
}

void SelectSort(LinkedList &L)
//单链表的简单选择排序
{
    if (!L)
        return;
    LinkedList p = L, q = NULL, r = NULL, t = NULL;
    while (p->next->next != NULL)
    {
        q = p->next;
        r = SelectMinNode(q);
        //找到q后最小结点
        if (!r)
            return;
        p->next = r;
        r = q;
        t = q->next;
        q->next = p->next->next;
        p->next->next = t;
        //交换q,r两个结点

        p = p->next;
    }
}

LinkedList SelectMinNode(LinkedList &q)
//返回在结点q后data最小的结点
{
    if (!q)
        return NULL;
    int temp = q->data;
    //temp为暂存数据，用于比较结点data大小，如果小于temp,则置换data
    LinkedList p = q, r = q;
    while (p->next != NULL)
    {
        if (p->next->data < temp)
        {
            temp = p->next->data;
            r = p->next; //当找到比temp小的data时，置换，并记录此时结点
        }
        if (r != q)
        {
            return r; //返回最小结点
        }
        p = p->next;
    }
}