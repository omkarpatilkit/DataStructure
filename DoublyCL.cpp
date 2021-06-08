#include <iostream>
using namespace std;

class SinglyCL
{
private:
    int iSize;
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    };
    typedef struct node Node;
    typedef struct node *NodePtr;
    typedef struct node **PNodePtr;

    NodePtr Head;
    NodePtr Tail;

public:
    SinglyCL()
    {
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }

    void InsertAtFirst(int);
    void InsertAtLast(int);
    void DeleteAtFirst();
    void DeleteAtLast();
    void InsertAtPosition(int, int);
    void DeleteAtPosition(int);
    int Count();
    void Display();
};

void SinglyCL::InsertAtFirst(int no)
{
    NodePtr newn = new Node;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
        Tail = Head;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;
    iSize++;
}

void SinglyCL::InsertAtLast(int no)
{
    NodePtr newn = new Node;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
        Tail = Head;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;
    iSize++;
}

void SinglyCL::DeleteAtFirst()
{
    NodePtr temp = Head;
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == Tail)
    {
        Head = NULL;
        Tail = NULL;
        delete (temp);
    }

    else
    {
        Head = Head->next;
        Head->prev = Tail;
        Tail->next = Head;
        delete (temp);
    }
    iSize--;
}

void SinglyCL::DeleteAtLast()
{
    if (Head == NULL)
    {
        return;
    }
    else if (iSize == 1)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }
    else
    {
        Tail = Tail->prev;
        delete (Tail->next);
        Tail->next = Head;
        Head->prev = Tail;
        iSize--;
    }
}

void SinglyCL::InsertAtPosition(int no, int pos)
{
    if (pos < 1 || pos > iSize + 1)
    {
        cout << "Please enter a valid position." << endl;
        return;
    }

    else if (pos == 1)
    {
        InsertAtFirst(no);
    }
    else if (pos == iSize + 1)
    {
        InsertAtLast(no);
    }

    else
    {
        NodePtr temp = Head;
        NodePtr newn = new Node;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < pos - 1; i++)
        {

            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
        iSize++;
    }
}

void SinglyCL ::DeleteAtPosition(int pos)
{
    if (pos < 1 || pos > iSize + 1)
    {
        cout << "Please enter a valid position." << endl;
        return;
    }

    else if (pos == 1)
    {
        DeleteAtFirst();
    }
    else if (pos == iSize + 1)
    {
        DeleteAtLast();
    }

    else
    {
        NodePtr temp = Head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        NodePtr temp2 = temp->next; //delete(temp->next->prev) smart move
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete (temp2);
        iSize--;
    }
}

void SinglyCL::Display()
{
    if (Head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    NodePtr temp = Head;
    for (int i = 0; i < iSize; i++)
    {
        cout << temp->data << '\t';
        temp = temp->next;
    }
    cout << endl;
    cout << "List contains " << iSize << " elements" << endl;
    cout << endl;
}

int SinglyCL::Count()
{
    return iSize;
}

int main()
{

    int iChoice = 1, iNo = 0, iRet = 0, iPos = 0;
    SinglyCL List1;

    while (iChoice != 0)
    {

        cout << "1 : To enter at First place." << endl;
        cout << "2 : To enter at Last place." << endl;
        cout << "3 : To delete at First place." << endl;
        cout << "4 : To delete at Last place." << endl;
        cout << "5 : To enter at Postion place." << endl;
        cout << "6 : To Delete at Position place." << endl;
        cout << "7 : To enter at First place." << endl;
        cout << "9 : To Display the list." << endl;
        cout << "10 : To Display number of elements in the list." << endl;
        cout << "0: To exit." << endl;
        cout << "____________________________________________" << endl;

        cout << "Please select the option:" << endl;
        cin >> iChoice;

        switch (iChoice)
        {
        case 1:
            cout << "Enter number to add at first place: " << endl;
            cin >> iNo;
            List1.InsertAtFirst(iNo);
            break;

        case 2:
            cout << "Enter number to add at Last place: " << endl;
            cin >> iNo;
            List1.InsertAtLast(iNo);
            break;

        case 3:
            List1.DeleteAtFirst();
            break;

        case 4:
            List1.DeleteAtLast();
            break;

        case 5:
            cout << "Enter number to add in List1: " << endl;
            cin >> iNo;
            cout << "Enter the position of number to add: " << endl;
            cin >> iPos;
            List1.InsertAtPosition(iNo, iPos);
            break;

        case 6:
            cout << "Enter the position of number to delete: " << endl;
            cin >> iPos;
            List1.DeleteAtPosition(iPos);
            break;

        case 9:
            List1.Display();
            break;

        case 10:
            iRet = List1.Count();
            cout << "Number of elements : " << iRet << endl;
            break;

        default:
            cout << "Please select a valid input: " << endl;
            break;
        }
    }

    return 0;
}