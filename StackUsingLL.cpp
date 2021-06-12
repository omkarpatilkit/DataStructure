#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} Node, *NodePtr;

class Stack
{

private:
    int iSize;
    NodePtr Head;

public:
    Stack();
    ~Stack();
    void Push(int);
    int Pop();
    int Peek();
    void Display();
    int Count();
};

Stack::Stack()
{
    cout << "Object created in Constructor" << endl;
    Head = NULL;
    iSize = 0;
}

Stack::~Stack()
{
    cout << "This is the destructor" << endl;
}

void Stack::Push(int no)
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

int Stack::Pop()
{
    int iReturn = 0;

    if (Head == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        NodePtr temp = Head;
        iReturn = Head->data;
        Head = Head->next;
        delete temp;
        iSize--;
    }
    return iReturn;
}

int Stack::Peek()
{
    return Head->data;
}

void Stack::Display()
{
    NodePtr temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

int Stack::Count()
{
    return iSize;
}

int main()
{
    Stack SObj;
    int iChoice = 1, iNo, iRet;

    while (iChoice != 0)
    {

        cout << "Please select the option\n";
        cout << "1 : Push the element\n";
        cout << "2 : Pop the element\n";
        cout << "3 : Display the elements\n";
        cout << "4 : Count number of elements\n";
        cout << "5 : Peek the Element\n";
        cout << "0 : Exit the application\n";
        cout << "----------------------------------\n";

        cin >> iChoice;
        switch (iChoice)
        {

        case 1:
            cout << "Please enter the number to add in: " << endl;
            cin >> iNo;
            SObj.Push(iNo);
            break;

        case 2:
            iRet = SObj.Pop();
            cout << iRet << endl;
            break;

        case 3:
            SObj.Display();
            break;

        case 4:
            cout << "Total num of elements are: " << SObj.Count() << endl;
            break;

        case 5:
            iRet = SObj.Peek();
            cout << "Value of top element is : " << iRet << "\n";
            break;

        case 0:
            delete &SObj;
            break;

        default:
            cout << "Please enter the proper option\n";
            break;
        }
    }

    return 0;
}