#include <stdio.h>
#include <stdlib.h>

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

int Count(NodePtr Head)
{
    static int iCnt = 0;
    if (Head != NULL)
    {
        iCnt++;
        Count(Head->lChild);
        Count(Head->rChild);
    }
    return iCnt;
}

int main()
{

    NodePtr root = NULL;

    int iChoice = 1, iNo = 0, iRet = 0;

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
            iRet = Count(root);
            printf("%d\n", iRet);
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