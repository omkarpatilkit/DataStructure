#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{

    int data;
    struct node *rChild;
    struct node *lChild;
} Node, *NodePtr, **PNodePtr;

void InsertNode(PNodePtr Head, int no)
{

    NodePtr temp = *Head;
    NodePtr newn = (Node *)malloc(sizeof(Node));
    newn->data = no;
    newn->lChild = NULL;
    newn->rChild = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }

    else
    {
        while (1)
        {
            if (no > temp->data)
            {
                if (temp->rChild == NULL)
                {
                    temp->rChild = newn;
                    break;
                }
                temp = temp->rChild;
            }
            else if (no < temp->data)
            {
                if (temp->lChild == NULL)
                {
                    temp->lChild = newn;
                    break;
                }
                temp = temp->lChild;
            }
            else
            {
                printf("Duplicate element\n");
                free(newn);
                break;
            }
        } // end of while

    } // else statement
}

void PreOrder(NodePtr Head)
{
    if (Head != NULL)
    {
        printf("%d\t", Head->data);
        PreOrder(Head->lChild);
        PreOrder(Head->rChild);
    }
}

void InOrder(NodePtr Head)
{
    if (Head != NULL)
    {
        InOrder(Head->lChild);
        printf("%d\t", Head->data);
        InOrder(Head->rChild);
    }
}

void PostOrder(NodePtr Head)
{
    if (Head != NULL)
    {
        PostOrder(Head->lChild);
        PostOrder(Head->rChild);
        printf("%d\t", Head->data);
    }
}

void Count(NodePtr Head, int *p)
{
    if (Head != NULL)
    {
        (*p)++;
        Count(Head->lChild, p);
        Count(Head->rChild, p);
    }
}

void NumberOfParent(NodePtr Head, int *p)
{

    if (Head != NULL)
    {
        if (Head->lChild != NULL || Head->rChild != NULL)
        {
            (*p)++;
        }
        NumberOfParent(Head->lChild, p);
        NumberOfParent(Head->rChild, p);
    }
}

void NumberOfLeaf(NodePtr Head, int *p)
{
    if (Head != NULL)
    {
        if (Head->lChild == NULL && Head->rChild == NULL)
        {
            (*p)++; //
        }
        NumberOfLeaf(Head->lChild, p);
        NumberOfLeaf(Head->rChild, p);
    }
}

bool Search(NodePtr Head, int no)
{
    NodePtr temp = Head;
    if (Head == NULL)
    {
        printf("Tree is Empty\n");
        return false;
    }
    else
    {
        while (1)
        {
            if (temp == NULL)
            {
                return false;
            }
            else if (no > temp->data)
            {
                temp = temp->rChild;
            }
            else if (no < temp->data)
            {
                temp = temp->lChild;
            }

            else if (no == temp->data)
            {
                return true;
            }
        }
    }
}

int main()
{

    NodePtr root = NULL;

    int iChoice = 1, iNo = 0, iRet = 0, i;
    bool bRet = false;

    while (iChoice != 0)
    {

        printf("Please select a option: \n");
        printf("Enter your choice\n");
        printf("1 : Insert node\n");
        printf("2 : Display Inorder\n");
        printf("3 : Display Preorder\n");
        printf("4 : Display Postorder\n");
        printf("5 : Count nodes\n");
        printf("6 : For all Orders at once\n");
        printf("7 : Enter number to search\n");
        printf("8 : Count the number of parents\n");
        printf("9 : Count the number of leaf\n");
        printf("0 : Terminate the appplication\n");

        scanf("%d", &iChoice);

        switch (iChoice)
        {

        case 1:
            printf("Please enter the number to entre: \n");
            scanf("%d", &iNo);
            InsertNode(&root, iNo);
            break;

        case 2:
            InOrder(root);
            printf("\n");
            break;

        case 3:
            PreOrder(root);
            printf("\n");
            break;

        case 4:
            PostOrder(root);
            printf("\n");
            break;

        case 5:
            i = 0;
            Count(root, &i);
            printf("%d\n", i);
            break;

        case 6:
            printf("this is by PreOrder: ");
            PreOrder(root);
            printf("\n");
            printf("this is by InOrder: ");
            InOrder(root);
            printf("\n");
            printf("this is by PostOrder: ");
            PostOrder(root);
            printf("\n");
            break;

        case 7:
            printf("Enter the number to search:\n");
            scanf("%d", &iNo);
            bRet = Search(root, iNo);
            if (bRet == true)
            {
                printf("%d present in BST\n", iNo);
            }
            else
            {
                printf("%d is not present in BST\n", iNo);
            }
            break;

        case 8:
            i = 0;
            NumberOfParent(root, &i);
            printf("Number of parents are %d\n", i);
            break;

        case 9:
            i = 0;
            NumberOfLeaf(root, &i);
            printf("Number of leaves are %d\n", i);
            break;

        case 0:
            printf("Thank you for using appplication\n");
            break;

        default:
            printf("Please enter proper choice\n");
            break;
        }
    } // end of while

    return 0;
}