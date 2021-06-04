/*
 * @Author: 许劲淇 
 * @Date: 2020-06-02 14:48:35 
 * @Last Modified by: 许劲淇
 * @Last Modified time: 2020-06-02 18:05:20
 */
#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void SelectSort(SqList &L);
int SelectMinKey(SqList &l, int i);

int main()
{
    SqList L = InitSqList();
    InputInfo(L);
    SelectSort(L);
    PrintSqList(L);

    system("pause");
    return 0;
}

void SelectSort(SqList &L)
{
    if (!L)
    {
        printf("error.\n");
        return;
    }
    int i, j;
    for (i = 1; i < L->length; i++)
    //从表头依次进行选择，找到第i个数左边最小的数与第i个交换
    {
        j = SelectMinKey(L, i);
        if (i != j)
            swap(L->r[i].key, L->r[j].key);
    }
}

void swap(int &a, int &b) //对整数进行交换
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int SelectMinKey(SqList &L, int i)
//循环找到在第i个元素后最小的元素
{
    if (!L)
    {
        printf("error.\n");
        return 0;
    }
    int j, min = L->r[i].key, flag = i;
    //采用变量min暂存已经搜索的数中最小的数
    //flag表明该数所在位置
    for (j = i + 1; j <= L->length; j++)
    {
        if (L->r[j].key < min)
        {
            min = L->r[j].key;
            flag = j;
        }
    }
    return flag;
}
SqList InitSqList() //创建链表
{
    SqList p = (SqList)malloc(sizeof(SqNode));
    if (!p)
        return NULL;
    memset(p->r, -1, MAXN + 1);
    p->length = 0;
    return p;
}

void InputInfo(SqList &L) //输入数据
{
    if (!L)
    {
        printf("error\n");
        return;
    }
    L->length = 1;
    char ch = 0;
    while (scanf("%d", &L->r[L->length].key) == 1)
    {
        if ((ch = getchar()) == '\n')
            return;
        L->length++;
    }
}

void PrintSqList(SqList &L)
{
    if (!L)
    {
        printf("error\n");
        return;
    }
    for (int i = 1; i <= L->length; i++)
        printf("%d ", L->r[i].key);
    printf("\n");
    return;
}