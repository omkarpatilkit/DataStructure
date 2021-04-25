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

// int Addition(node **Head)
// {
// node *ptr = *Head;
// int addition = 0;
// while (ptr != NULL)
// {
// addition = addition + ptr->data;
// ptr = ptr->Next;
// }
// return addition;
// }
int Max(node **Head)
{
    int M = 0;
    node *ptr = *Head;
    while (ptr != NULL)
    {
        if (ptr->data > M)
        {
            M = ptr->data;
        }
        ptr = ptr->Next;
    }
    return M;
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

int main()
{
    node *First = NULL;
    int Maxi = 0;
    InsertFirst(&First, 90);
    InsertFirst(&First, 30);
    InsertFirst(&First, 50);
    InsertFirst(&First, 40);
    InsertFirst(&First, 30);
    InsertFirst(&First, 70);
    InsertFirst(&First, 10);

    printList(&First);
    Maxi = Max(&First);
    printf("Maximum is %d", Maxi);

    return 0;
}