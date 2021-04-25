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

int Addition(node **Head)
{
    node *ptr = *Head;
    int addition = 0;
    while (ptr != NULL)
    {
        addition = addition + ptr->data;
        ptr = ptr->Next;
    }
    return addition;
}

int main()
{
    node *First = NULL;
    int Add = 0;
    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 50);
    InsertFirst(&First, 40);
    InsertFirst(&First, 30);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    Add = Addition(&First);
    printf("addition is %d", Add);

    return 0;
}