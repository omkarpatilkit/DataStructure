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

int GiveSumOfNum(int no)
{
    int sum = 0;
    int temp = no;
    int digi = 0;
    while (temp != 0)
    {
        digi = temp % 10;
        sum = sum + digi;
        temp = temp / 10;
    }
    return sum;
}

void SumOfNum(node **Head)
{
    node *ptr = *Head;
    int res = 0;
    while (ptr != NULL)
    {
        res = GiveSumOfNum(ptr->data);
        printf("%d ", res);
        ptr = ptr->Next;
        res = 0;
    }
}

int main()
{
    node *First = NULL;
    // int Add = 0;
    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 19);
    InsertFirst(&First, 43);
    InsertFirst(&First, 30);
    InsertFirst(&First, 23);
    InsertFirst(&First, 11);

    SumOfNum(&First);

    return 0;
}