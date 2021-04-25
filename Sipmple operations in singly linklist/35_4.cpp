#include <iostream>
#include <math.h>
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

int InternalMulti(int no)
{
    int digi = 0;
    int temp = no;
    int multi = 1;

    while (temp != 0)
    {
        digi = temp % 10;
        if (digi != 0)
        {
            multi = multi * digi;
        }
        temp = temp / 10;
    }
    return multi;
}

void printList(node **Head)
{
    node *ptr = *Head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->Next;
    }
}

void Reverseinternal(node **Head)
{
    node *ptr = *Head;
    int RevNo = 0;
    while (ptr != NULL)
    {
        RevNo = InternalMulti(ptr->data);

        printf("%d ", RevNo);

        ptr = ptr->Next;
    }
    // printList(Head);
}

int main()
{
    node *First = NULL;
    // int SecMax = 0;
    InsertFirst(&First, 78);
    InsertFirst(&First, 31);
    InsertFirst(&First, 6);
    InsertFirst(&First, 414);
    InsertFirst(&First, 30);
    InsertFirst(&First, 23);
    InsertFirst(&First, 11);

    Reverseinternal(&First);
    // printf("Second maximum is %d", SecMax);

    return 0;
}