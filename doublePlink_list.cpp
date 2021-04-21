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

void insertAtFirst(node **Head, int n)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = n;
    ptr->Next = *Head;
    *Head = ptr;
}

void deleteFirst(node **Head)
{
    node *ptr = *Head;
    *Head = ptr->Next;
    ptr->Next = NULL;
    free(ptr);
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

void deleteLast(node **Head)
{
    node *ptr = *Head;
    while (ptr->Next->Next != NULL)
    {
        ptr = ptr->Next;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp = ptr->Next;
    ptr->Next = NULL;
    free(temp);
}

int LenList(node *Head)
{
    int cnt = 0;
    while (Head != NULL)
    {
        cnt++;
        Head = Head->Next;
    }
    return cnt;
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
    int Length = 0;

    printList(First);
    insertFirstEle(&First, 60);
    printList(First);
    insertAtLast(&First, 40);
    printList(First);
    insertAtFirst(&First, 10);
    printList(First);
    Length = LenList(First);
    deleteFirst(&First);
    printList(First);
    deleteLast(&First);
    printList(First);
    printf("Length of list was %d: ", Length);
    return 0;
}