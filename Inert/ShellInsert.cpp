/*
 * @Author: 许劲淇 
 * @Date: 2020-06-02 10:12:12 
 * @Last Modified by: 许劲淇
 * @Last Modified time: 2020-06-02 10:56:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "SqList.h"

void ShellInsert(SqList &L, int dk);
void ShellSort(SqList &L, int dlta[], int t);

int main()
{
    SqList L = InitSqList();
    int n;
    scanf("%d", &n);
    int dlta[MAXN];
    for (int i = 0; i < n; i++)
        scanf("%d", &dlta[i]);
    InputInfo(L);
    ShellSort(L, dlta, n);
    PrintSqList(L);

    system("pause");
    return 0;
}

void ShellInert(SqList &L, int dk)
//对记录序列进行希尔排序，增量为dk
{
    int i, j;
    for (i = dk + 1; i <= L->length; i++)
    {
        if (L->r[i].key < L->r[i - dk].key)
        {
            L->r[0] = L->r[i]; //将需要置换的数据暂存于r[0]
            for (j = i - dk; j > 0 && (L->r[0].key < L->r[j].key); j -= dk)
                L->r[j + dk] = L->r[j];
            L->r[j + dk] = L->r[0];
        }
    }
}

void ShellSort(SqList &L, int dlta[], int t)
//dlta[]存放增量序列，调用ShellInert将数据序列分割为多个小块
//在小块内进行直接插入排序，并将记录序列进行排序
{
    for (int k = 0; k < t; k++)
        ShellInert(L, dlta[k]);
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
        printf("%.2d ", L->r[i].key);
    printf("\n");
    return;
}