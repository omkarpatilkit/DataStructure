// Singly linear linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node *NodePtr;
typedef struct node **PNodePtr;

int Count(PNodePtr Head)
{
    NodePtr temp = *Head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void InsertAtFirst(PNodePtr Head, int no)
{

    NodePtr newn = NULL;
    newn = (struct node *)malloc(sizeof(Node));
    newn->data = no;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }

    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertAtLast(PNodePtr Head, int no)
{

    struct node *newn = NULL;
    NodePtr temp = *Head;

    newn = (struct node *)malloc(sizeof(struct node));
    newn->data = no;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void InsertAtPosition(PNodePtr Head, int no, int pos)
{
    int len = Count(Head);
    NodePtr temp = *Head;
    NodePtr newn = NULL;
    newn = (struct node *)malloc(sizeof(Node));
    newn->data = no;
    newn->next = NULL;

    if (pos == 1)
    {
        InsertAtFirst(Head, no);
    }
    else if (pos == (len + 1))
    {
        InsertAtLast(Head, no);
    }
    else if (pos > (len + 1) || pos < 1)
    {
        printf("please enter valid position");
    }
    else if (pos == 2)
    {

        newn->next = temp->next;
        temp->next = newn;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        { //  1 2 3 4 5 6
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PNodePtr Head)
{

    if (*Head == NULL)
    {
        return;
    }

    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }

    else
    {
        NodePtr temp = *Head;
        NodePtr temp2 = *Head;
        temp = temp->next;
        *Head = temp;
        temp2 = NULL;
        free(temp2);
    }
}

void DeleteLast(PNodePtr Head)
{
    NodePtr temp = *Head;
    NodePtr temp2 = NULL;
    if (*Head == NULL)
    {
        return;
    }

    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
    }
}

void DeleteAtPosition(PNodePtr Head, int pos)
{
    int len = Count(Head);
    NodePtr temp2 = NULL;
    NodePtr temp = *Head;
    if (pos == 1)
    {
        DeleteFirst(Head);
    }
    else if (pos == (len + 1))
    {
        DeleteLast(Head);
    }
    else if (pos > (len + 1) || pos < 1)
    {
        printf("please enter valid position");
    }
    else if (pos == 2)
    {
        temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        { //  1 2 3 4 5 6
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

void DisplayList(PNodePtr Head)
{
    NodePtr temp = *Head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    NodePtr First = NULL;
    int iValue = 0, iChoice = 1, iPos = 0, iRet = 0, iCount = 0;

    while (iChoice != 0)
    {

        printf("\n____________________________________\n");
        printf("Enter your action on Linked list : \n");
        printf("1 : Insert node at First position\n");
        printf("2 : Insert node at Last position\n");
        printf("3 : Delete node at First position\n");
        printf("4 : Delete node at Last position\n");
        printf("5 : Insert node at Last position\n");
        printf("6 : Delete node at Last position\n");
        printf("9 : Display list\n");
        printf("10 : Display Total number of list\n");
        printf("0 : to Exit the programme\n");
        printf("\n____________________________________\n");
        printf("Please select a option : \n");
        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 0:
            printf("Closing the link list\n");
            break;

        case 1:
            printf("Enter data to insert : \n");
            scanf("%d", &iValue);
            InsertAtFirst(&First, iValue);
            break;

        case 2:
            printf("Enter data to insert : \n");
            scanf("%d", &iValue);
            InsertAtLast(&First, iValue);
            break;

        case 3:
            DeleteFirst(&First);
            break;

        case 4:
            DeleteLast(&First);
            break;

        case 5:
            printf("Enter the number to add in Linked list:\n");
            scanf("%d", &iValue);
            printf("Enter the position to insert\n");
            scanf("%d", &iPos);
            InsertAtPosition(&First, iValue, iPos);
            break;

        case 6:
            printf("Enter the position to delete in Linked list\n");
            scanf("%d", &iPos);
            DeleteAtPosition(&First, iPos);
            break;

        case 9:
            DisplayList(&First);
            break;

        case 10:
            iCount = Count(&First);
            printf("%d number of items in the list\n", iCount);
            break;

        default:
            printf("Please enter valid option \n");
            break;
        } // End of switch
    }     // End of while
    return 0;
} // End of main