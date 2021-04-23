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

void insertAtPos(node **Head, int n, int k)
{
    int Len = 0;
    Len = LenList(*Head);
    if (k > (Len + 1))
    {
        printf("please enter valid no. ");
        return;
    }
    else if (k == 0 || k == 1)
    {
        insertAtFirst(Head, n);
    }
    else if (k == (Len + 1))
    {
        insertAtLast(Head, n);
    }
    else if (k == 2)
    {
        node *ptr = *Head;
        node *newn = (node *)malloc(sizeof(node));
        node *temp = (node *)malloc(sizeof(node));
        temp = ptr->Next;
        ptr->Next = newn;
        newn->data = n;
        newn->Next = temp;
        // free(temp);
    }
    else
    {
        node *ptr = *Head;
        for (int i = 0; i < (k - 1); i++)
        {
            ptr = ptr->Next;
        }
        node *temp = (node *)malloc(sizeof(node));
        temp = ptr->Next;
        node *newn = (node *)malloc(sizeof(node));
        ptr->Next = newn;
        newn->data = n;
        newn->Next = temp;
        //free(temp);
        //free(ptr);
    }
}

int Freqof(node *Head, int n)
{
    int cnt = 0;
    while (Head->Next != NULL)
    {
        if (Head->data == n)
        {
            cnt++;
        }
        Head = Head->Next;
    }
    return cnt;
}

void delePertEle(node **Head, int n)
{
    node *ptr = *Head;
    node *check = *Head;
    check = check->Next;
    while ((ptr->Next != NULL) && (check != NULL))
    {

        if ((ptr->data) == n)
        {
            *Head = ptr->Next;
            return;
        }

        if ((check->data) == n)
        {

            if (check->Next == NULL)
            {
                deleteLast(Head);
            }
            else
            {

                ptr->Next = check->Next;
            }
        }
        ptr = ptr->Next;
        check = check->Next;
    }
}

int main()
{
    node *First = (node *)malloc(sizeof(node));
    First->Next = NULL;
    First->data = 1;
    int Length = 0;
    int f30 = 0;

    printList(First);
    insertFirstEle(&First, 60);
    printList(First);
    insertAtLast(&First, 40);
    printList(First);
    insertAtFirst(&First, 10);
    printList(First);

    insertAtPos(&First, 30, 2);
    printList(First);
    insertAtPos(&First, 100, 2);
    insertAtPos(&First, 30, 4);
    printList(First);
    f30 = Freqof(First, 30);
    printf("frqency of 30  is: %d\n", f30);

    Length = LenList(First);
    deleteFirst(&First);
    printList(First);
    deleteLast(&First);
    printList(First);
    delePertEle(&First, 100);
    printList(First);
    printf("Length of list was: %d\n", Length);
    return 0;
}