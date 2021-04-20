#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *Next;
};

node *insertAtFirst(node *Head, int n)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->Next = Head;
    ptr->data = n;
    return ptr;
}

node *deleteFirst(node *Head)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = Head;
    Head = Head->Next;
    free(ptr);
    return Head;
}

void deleteLast(node *Head)
{
    while (Head->Next->Next != NULL)
    {
        Head = Head->Next;
    }
    node *ptr = (node *)malloc(sizeof(node));
    ptr = Head->Next;
    Head->Next = NULL;
    free(ptr);
}

void insertAtLast(node *Head, int n)
{
    while (Head->Next != NULL)
    {
        Head = Head->Next;
    }

    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = n;
    Head->Next = ptr;
    ptr->Next = NULL;
}
void printList(node *Head)
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
    First->data = 1;
    First->Next = NULL;

    insertAtLast(First, 40);
    printList(First);
    First = insertAtFirst(First, 60);
    printList(First);
    deleteLast(First);
    printList(First);
    First = deleteFirst(First);
    printList(First);

    return 0;
}