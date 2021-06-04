#include <stdio.h>
#include "SqList.h"
#include <memory.h>
#include <stdlib.h>

void Merge(RedType r[], int low, int high, int mid);
void MSort(SqList &L, int l, int r);
void MergeSort(SqList &L, int l, int r);

int main()
{
    SqList L = InitSqList();
    InputInfo(L);
    MergeSort(L, 1, L->length);
    PrintSqList(L);

    system("pause");
    return 0;
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

void Merge(RedType a[], int low, int high, int mid)
{
    int r[MAXN], i, j, k;
    for (k = low + 1; k <= high; k++)
        r[k - low] = a[k];
    i = low;
    j = mid + 1;
    for (k = low; k <= high; k++)
    {
        if (i > mid)
        {
            a[k] = r[j - low];
            j++;
        }
        else if (j > high)
        {
            a[k] = r[j - low];
            i++;
        }
        else if (r[i - low] > r[j - low])
        {
            a[k] = r[j - low];
            j++;
        }
        else
        {
            a[k] = r[i - low];
            i++;
        }
    }
}
void MSort(SqList &L, int l, int r) {}
void MergeSort(SqList &L, int l, int r) {}