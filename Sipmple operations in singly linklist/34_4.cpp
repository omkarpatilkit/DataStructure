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

int SecondMaxi(node **Head)
{
    node *ptr = *Head;
    int Max = 0;
    int Smax = 0;
    while (ptr != NULL)
    {
        if (Max < ptr->data)
        {
            Smax = Max;
            Max = ptr->data;
        }
        else if (Smax < ptr->data)
        {
            Smax = ptr->data;
        }
        ptr = ptr->Next;
        
    }
    return Smax;
}

int main()
{
    node *First = NULL;
    int SecMax = 0;
    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 19);
    InsertFirst(&First, 43);
    InsertFirst(&First, 30);
    InsertFirst(&First, 23);
    InsertFirst(&First, 11);

    SecMax = SecondMaxi(&First);
    printf("Second maximum is %d", SecMax);

    return 0;
}