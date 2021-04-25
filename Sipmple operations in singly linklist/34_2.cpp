#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *Next;
};

void InsertFirst(node **Head, int n)
{
    node *newn = (node *)malloc(sizeof(node));
    newn->data = n;
    newn->Next = NULL;
    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->Next = *Head;
        *Head = newn;
    }
}

int IsPrime(int no)
{
    int res = 0;
    for (int i = 2; i < (no / 2); i++)
    {
        if (no % i == 0)
        {
            res = 0;
            return res;
        }
    }
    res = 1;
    return res;
}

void PrimeNo(node **Head)
{
    node *ptr = *Head;
    int res = 0;
    while (ptr != NULL)
    {
        res = IsPrime(ptr->data);
        if (res == 1)
        {
            printf("%d ", ptr->data);
        }
        ptr = ptr->Next;
        res = 0;
    }
}

int main()
{
    node *First = NULL;
    // int Add = 0;
    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 19);
    InsertFirst(&First, 43);
    InsertFirst(&First, 30);
    InsertFirst(&First, 23);
    InsertFirst(&First, 11);

    PrimeNo(&First);

    return 0;
}