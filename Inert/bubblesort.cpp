/*
 * @Author: 许劲淇 
 * @Date: 2020-06-02 11:01:16 
 * @Last Modified by: 许劲淇
 * @Last Modified time: 2020-06-02 11:20:59
 */
#include "SqList.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void bubblesort(SqList &L);

int main()
{
    SqList L = InitSqList();
    InputInfo(L);
    bubblesort(L);
    PrintSqList(L);

    system("pause");
    return 0;
}

void bubblesort(SqList &L)
//通过将相邻的元素比较，依次找到剩余序列中最大的元素
//反复进行n次循环
//利用flag记录是否发生交换，若无交换，则排序结束
{
    KeyType temp;
    int i = L->length, flag = 1;
    while ((i > 1) && flag)
    {
        flag = 0;
        for (int j = 1; j < i; j++)
            if (L->r[j].key > L->r[j + 1].key)
            {
                temp = L->r[j].key;
                L->r[j].key = L->r[j + 1].key;
                L->r[j + 1].key = temp;
                flag = 1;
            }
        i--;
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