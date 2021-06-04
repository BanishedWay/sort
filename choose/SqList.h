#define MAXN 1000

typedef int KeyType;

typedef struct
{
    KeyType key;
} RedType;
typedef struct
{
    RedType r[MAXN + 1];
    int length;
} * SqList, SqNode;

SqList InitSqList();
void InputInfo(SqList &L);
void PrintSqList(SqList &L);
void swap(int &a, int &b);