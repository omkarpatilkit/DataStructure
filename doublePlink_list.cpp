#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *Next;
};

void insertFirstEle(node **Head, int n)
{
    node *ptr = *Head;
    if (ptr->Next == NULL)
    {
        ptr->data = n;
        *Head = ptr;
    }
    else
    {
        return;
    }
}

void insertAtLast(node **Head, int n)
{
    node *ptr = *Head;

    while (ptr->Next != NULL)
    {
        ptr = ptr->Next;
    }

    node *newn = (node *)malloc(sizeof(node));
    if (newn == NULL)
    {
        printf("Unable to allcate node ");
        return;
    }

    newn->data = n;
    newn->Next = NULL;
    ptr->Next = newn;
}

printList(node *Head)
{
    while (Head != NULL)
    {
        printf("%d ", Head->data);
        Head = Head->Next;
    }
    printf("\n");
}
int main()
{
    node *First = (node *)malloc(sizeof(node));
    First->Next = NULL;
    First->data = 1;

    printList(First);
    insertFirstEle(&First, 60);
    printList(First);
    insertAtLast(&First, 40);
    printList(First);
    return 0;
}