/*
 * @Author: 许劲淇 
 * @Date: 2020-06-02 11:24:50 
 * @Last Modified by: 许劲淇
 * @Last Modified time: 2020-06-02 11:41:12
 */
#include "SqList.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int Partition(SqList &L, int low, int high);  //一次划分
void QuickSort(SqList &L, int low, int high); //快速排序
void swap(int &a, int &b);                    //交换整数

int main()
{
    SqList L = InitSqList();
    InputInfo(L);
    QuickSort(L, 1, L->length);
    PrintSqList(L);

    system("pause");
    return 0;
}

int Partition(SqList &L, int low, int high)
//循环找到枢轴所处的位置
//将序列分为大于枢轴和小于枢轴的两个序列
//返回枢轴所在的位置
{
    int pivotkey = L->r[low].key; //将序列首记录为枢轴
    L->r[0] = L->r[low];          //将数轴元素的值暂存到r[0]中
    while (low < high)
    {
        while (low < high && L->r[high].key >= pivotkey)
            //循环找到在枢轴右侧小于枢轴元素的记录
            high--;
        L->r[low] = L->r[high]; //将该记录交换到枢轴左侧
        while (low < high && L->r[low].key <= pivotkey)
            //循环找到在枢轴左侧大于枢轴元素的记录
            low++;
        L->r[high] = L->r[low]; //将该记录交换到枢轴右侧
    }
    L->r[low] = L->r[0]; //将原枢轴元素的值重新赋给枢轴
    return low;          //返回枢轴所在位置
}

void QuickSort(SqList &L, int low, int high)
//对数据序列进行快速排序,对一次划分后的子序列进行快速排序
//采用递归对数据序列进行多次划分，直至序列有序
{
    if (!L)
    {
        printf("error.\n");
        return;
    }
    if (low < high) //序列长度大于1
    {
        int pivotloc = Partition(L, low, high);
        //一次划分,将序列分为两个子序列,获取枢轴位置
        QuickSort(L, low, pivotloc - 1);
        //小于枢轴的子序列递归排序
        QuickSort(L, pivotloc + 1, high);
        //大于枢轴的子序列递归排序
    }
    return;
}
SqList InitSqList() //创建链表
{
    SqList p = (SqList)malloc(sizeof(SqNode));
    if (!p)
        return NULL;
    memset(p->r, -1, MAXN + 1);
    //初始化顺序表内值为-1
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
            //当输入最后一个数据输入换行符时结束输入
            return;
        L->length++;
    }
}

void PrintSqList(SqList &L) //输出顺序表内数据
{
    if (!L)
    {
        printf("error\n");
        return;
    }
    int i;
    for (i = 1; i < L->length; i++)
        printf("%d ", L->r[i].key);
    printf("%d\n", L->r[i].key);
    return;
}