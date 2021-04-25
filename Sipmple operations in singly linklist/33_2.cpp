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

int SearchFirstOcc(node **Head, int n)
{
    node *ptr = *Head;
    int cnt = 0;
    while (ptr->Next != NULL)
    {
        cnt++;
        if (ptr->data == n)
        {

            return cnt;
        }
        ptr = ptr->Next;
    }
}

int main()
{
    node *First = NULL;
    int FirstOcc = 0;
    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 50);
    InsertFirst(&First, 40);
    InsertFirst(&First, 30);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    FirstOcc = SearchFirstOcc(&First, 30);
    printf("First Occ of 30 is at %d", FirstOcc);

    return 0;
}