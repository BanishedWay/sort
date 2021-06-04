/*
 * @Author: 许劲淇 
 * @Date: 2020-06-01 16:04:29 
 * @Last Modified by: 许劲淇
 * @Last Modified time: 2020-06-01 17:59:08
 */
#include "SqList.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void InsertSort(SqList &L);

int main()
{
    SqList L = InitSqList();
    InputInfo(L);
    InsertSort(L);
    PrintSqList(L);

    system("pause");
    return 0;
}
void InsertSort(SqList &L)
//直接插入排序,r[0]为监视点,
//时间复杂度为O(n^2),适用于记录数量小的情况
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i].key < L->r[i - 1].key)
        //当存在第i个数的值比前一个小时，
        //将监视哨设为r[i]，进行插入操作
        //并将r[0]作为暂存，便于记录后移
        {
            L->r[0] = L->r[i];
            for (j = i - 1; L->r[j].key > L->r[0].key; j--)
                L->r[j + 1] = L->r[j];
            L->r[j + 1] = L->r[0];
            //所以大于r[i]的数后移一位
            //在找到插入点后直接插入
        }
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