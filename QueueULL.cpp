#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} Node, *NodePtr;

class Queue
{
private:
    NodePtr Head;
    int iSize;

public:
    Queue()
    {
        Head = NULL; //
        iSize = 0;
    }

    void Display();
    void Enqueue(int);
    int Dequeue();
    int Count();
};

void Queue::Enqueue(int no)
{
    NodePtr newn = new Node;
    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }

    else
    {
        newn->next = Head;
        Head = newn;
    }
    iSize++;
}

int Queue::Dequeue()
{
    int iReturn;
    if (Head == NULL)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    else if (Head->next == NULL)
    {
        iReturn = Head->data;
        delete Head;
        Head = NULL;
        iSize--;
        return iReturn;
    }
    else
    {
        NodePtr temp = Head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        iReturn = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        iSize--;
        return iReturn;
    }
}

int Queue::Count()
{
    return iSize;
}

void Queue::Display()
{
    NodePtr temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    Queue obj;
    int iChoice = 1, iNo = 0, iRet = 0;
    while (iChoice != 0)
    {
        cout << "Pleaseeneter the option\n";
        cout << "1 : Insert the element\n";
        cout << "2 : Delete the element\n";
        cout << "3 : Display the elements\n";
        cout << "4 : Count the enumber of elements\n";
        cout << "0 : Terminate the application\n";
        cin >> iChoice;
        switch (iChoice)
        {
        case 1:
            cout << "Enter th elemenet\n";
            cin >> iNo;
            obj.Enqueue(iNo);
            break;

        case 2:
            iRet = obj.Dequeue();
            cout << "Removed element is : " << iRet << "\n";
            break;

        case 3:
            obj.Display();
            break;

        case 4:
            iRet = obj.Count();
            cout << "Number of elements in queue are : " << iRet << "\n";
            break;

        case 0:
            cout << "Thank you for using the application\n";
            break;

        default:
            cout << "Please enter the proper choice\n";
            break;
        } // End of switch
    }     // End of while

    return 0;
}