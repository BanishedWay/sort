/*
 * @Author: 许劲淇 
 * @Date: 2020-06-02 17:42:56 
 * @Last Modified by: 许劲淇
 * @Last Modified time: 2020-06-02 18:13:04
 */
#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void HeapAdjust(SqList &L, int i, int length);
void HeapSort(SqList &L);

int main()
{
    SqList L = InitSqList();
    InputInfo(L);
    HeapSort(L);
    PrintSqList(L);

    system("pause");
    return 0;
}

void HeapAdjust(SqList &L, int i, int length)
//对大顶堆进行调整
{
    int temp = L->r[i].key;
    for (int k = i * 2; k <= length; k = k * 2)
    //从根结点的左结点开始从上往下，从左往右调整大顶堆
    {
        if (k < length && (L->r[k].key < L->r[k + 1].key))
            //如果左结点的值小于右结点，则k指向右结点
            k++;
        if (L->r[k].key > temp)
        //当第k个结点的值大于根结点时，将第k个结点的值赋给根结点，将i置换k
        //依次循环直到将剩余的结点改造成大顶堆
        {
            L->r[i].key = L->r[k].key;
            i = k;
        }
        else
        {
            break;
        }
    }
    L->r[i].key = temp; //将最初根结点的值赋给需要被替换的结点
}
void swap(int &a, int &b) //对整数进行交换
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void HeapSort(SqList &L)
{
    //循环构建大顶堆
    for (int i = L->length / 2; i > 0; i--)
        //从第一个非叶子结点开始，从下往上，从右往左调整结构
        HeapAdjust(L, i, L->length);
    PrintSqList(L);
    for (int i = L->length; i > 1; i--)
    //置换堆顶元素与堆尾元素，对剩余元素重新调整为大顶堆
    {
        swap(L->r[1].key, L->r[i].key);
        HeapAdjust(L, 1, i - 1);
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

void PrintSqList(SqList &L) //输出序列
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