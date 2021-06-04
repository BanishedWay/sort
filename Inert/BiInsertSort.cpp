/*
 * @Author: 许劲淇 
 * @Date: 2020-06-01 17:43:37 
 * @Last Modified by: 许劲淇
 * @Last Modified time: 2020-06-01 17:58:33
 */
#include "SqList.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void BiInsertSort(SqList &L);

int main()
{
    SqList L = InitSqList();
    InputInfo(L);
    BiInsertSort(L);
    PrintSqList(L);

    system("pause");
    return 0;
}

void BiInsertSort(SqList &L)
//折半插入排序法，时间复杂度为O(n^2)
//适用于记录量大的情况
{
    if (!L)
    {
        printf("error\n");
        return;
    }
    int low, high;
    for (int i = 2; i <= L->length; i++)
    {
        L->r[0] = L->r[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            int m = (low + high) / 2;
            if (L->r[0].key < L->r[m].key)
                high = m - 1;
            else
            {
                low = m + 1;
            }
        }
        for (int j = i - 1; j >= high + 1; j--)
            L->r[j + 1] = L->r[j];
        L->r[high + 1] = L->r[0];
    }
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