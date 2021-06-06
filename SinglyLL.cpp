#include <iostream>
using namespace std;

class SinglyLl
{

private:
    int iSize = 0;
    struct node
    {
        int data;
        struct node *next;
    };

    typedef struct node Node;
    typedef struct node *NodePtr;
    typedef struct node **PNodePtr;

    NodePtr Head;

public:
    int iValue = 0, iCount = 0;
    SinglyLl()
    {
        Head = NULL;
        iSize = 0;
    }

    void InsertAtFirst(int);
    void InsertAtLast(int);
    void DeleteAtFirst();
    void DeleteAtLast();
    void InsertAtPosition(int, int);
    void DeleteAtPosition(int);
    void Display();
    int Count();
};

void SinglyLl::InsertAtFirst(int no)
{
    NodePtr newn = NULL;
    newn = new Node;
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

void SinglyLl::InsertAtLast(int no)
{
    NodePtr newn = new Node;
    newn->data = no;
    newn->next = NULL;
    NodePtr temp = Head;

    if (Head == NULL)
    {
        Head = newn;
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iSize++;
}

void SinglyLl::DeleteAtFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        Head = NULL;
        iSize--;
    }
    else
    {
        NodePtr temp = Head;
        Head = Head->next;
        delete (temp);
        iSize--;
    }
}

void SinglyLl::DeleteAtLast()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        Head = NULL;
        iSize--;
    }
    else
    {
        NodePtr temp = Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
        iSize--;
    }
}

void SinglyLl::InsertAtPosition(int no, int pos)
{
    //int iSize = this->Count;
    if (pos == 1)
    {
        this->InsertAtFirst(no);
    }

    else if (pos == (iSize + 1))
    {
        this->InsertAtLast(no);
    }
    else if ((pos < 1) || (pos > iSize + 1))
    {
        cout << "Please enter a valid position";
        return;
    }
    else
    {
        NodePtr newn = new Node;
        newn->data = no;
        newn->next = NULL;

        NodePtr temp = Head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

void SinglyLl::DeleteAtPosition(int pos)
{
    //int iSize = this->Count;
    if (pos == 1)
    {
        this->DeleteAtFirst();
    }

    else if (pos == (iSize + 1))
    {
        this->DeleteAtLast();
    }
    else if ((pos < 1) || (pos > iSize + 1))
    {
        cout << "Please enter a valid position";
        return;
    }
    else
    {
        NodePtr temp = Head;
        NodePtr temp2 = NULL;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp->next->next;
        delete (temp2);
        iSize--;
    }
}

void SinglyLl::Display()
{
    NodePtr temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << '\t';
        temp = temp->next;
    }
    cout << '\n';
    cout << iSize << " Number of elements in List" << '\n';
}

int SinglyLl::Count()
{
    return iSize;
}

int main()
{
    int iChoice = 1, iNo = 0, iRet = 0, iPos = 0;
    SinglyLl List1;

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