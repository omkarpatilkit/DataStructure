#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void InsertAtFirst(node **Head, int n)
{
    node *ptr = new node;
    if (ptr == NULL)
    {
        printf("Unable to assign memory");
        return;
    }
    ptr->data = n;
    ptr->next = NULL;

    if (*Head == NULL)
    {
        *Head = ptr;
    }
    else
    {
        ptr->next = *Head;
        *Head = ptr;
    }
}

void InsertAtLast(node **Head, int n)
{
    node *newn = new node;
    node *ptr = *Head;
    if (newn == NULL)
    {
        printf("Unable to assign memory");
        return;
    }
    newn->data = n;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }

    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newn;
    }
}

int LengthList(node *Head)
{
    int cnt = 0;
    node *ptr = Head;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }

    return cnt;
}

void InsertAtN(node **Head, int n, int pos)
{
    node *ptr = *Head;
    node *newn = new node;
    node *temp = new node;
    newn->data = n;

    int Len = LengthList(ptr);
    if (pos < 1 || pos > Len)
    {
        printf("Please enter Valid input");
        return;
    }
    else if (pos == 1)
    {
        InsertAtFirst(Head, n);
    }
    else if (pos == Len)
    {
        InsertAtLast(Head, n);
    }
    else if (pos == 2)
    {
        temp = ptr->next;
        ptr->next = newn;
        newn->next = temp;
    }

    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = newn;
        newn->next = temp;
    }
}

void deleteAt(node **Head, int pos)
{
    node *prev = NULL;
    node *curr = *Head;
    node *after = (*Head)->next;
    node *temp = NULL;

    for (int i = 1; (i < pos - 1) && (curr != NULL); i++)
    {
        prev = curr;
        curr = after;
        after = after->next;
    }
    temp = curr->next;
    curr->next = after->next;
    free(temp);
}

void deleteNum(node **Head, int n)
{
    node *prev = new node;
    node *curr = *Head;
    node *after = (*Head)->next;
    node *temp = NULL;

    while (after != NULL)
    {
        if (curr->data == n)
        {
            prev->next = after;

            temp = curr;
            free(temp);

            curr = after;
            after = after->next;
        }

        else
        {
            prev = curr;
            curr = curr->next;
            after = after->next;
        }
    }
}

void printList(node **Head)
{
    node *ptr = *Head;
    while (ptr != NULL)
    {
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << '\n';
}

int main()
{
    node *First = (node *)malloc(sizeof(node));
    First = NULL;
    InsertAtFirst(&First, 60);
    InsertAtFirst(&First, 50);
    InsertAtFirst(&First, 40);
    InsertAtFirst(&First, 30);
    InsertAtFirst(&First, 20);
    InsertAtFirst(&First, 20);
    InsertAtFirst(&First, 20);
    InsertAtFirst(&First, 10);

    InsertAtLast(&First, 90);
    InsertAtLast(&First, 90);
    InsertAtLast(&First, 90);
    InsertAtLast(&First, 100);
    InsertAtLast(&First, 110);

    InsertAtN(&First, 70, 7);
    printList(&First);

    deleteAt(&First, 5);
    printList(&First);

    deleteNum(&First, 90);
    printList(&First);
    deleteNum(&First, 20);
    printList(&First);

    return 0;
}