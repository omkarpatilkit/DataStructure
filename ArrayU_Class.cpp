#include <iostream>
using namespace std;

class Array
{

private:
    int *Arr;
    int iSize;

public:
    Array(int);
    ~Array();
    void Accept();
    void Display();
    int Addition();
};

Array::Array(int no)
{
    iSize = no;
    Arr = new int[iSize];
}

Array::~Array()
{
    cout << "This is destructor" << endl;
    delete[] Arr;
}

void Array::Display()
{
    for (int i = 0; i < iSize; i++)
    {
        cout << Arr[i] << endl;
    }
}

void Array::Accept()
{
    for (int i = 0; i < iSize; i++)
    {
        cout << "Enter no. " << i + 1 << ": ";
        cin >> Arr[i];
    }
}

int Array::Addition()
{
    int iSum = 0; //
    for (int i = 0; i < iSize; i++)
    {
        iSum = iSum + Arr[i];
    }
    return iSum;
}

int main()
{
    int iRet = 0, iNo = 0;
    cout << "Enter the size of Array\n";
    cin >> iNo;
    Array A(iNo);
    A.Accept();
    A.Display();
    A.Addition();
    //A.~Array();

    return 0;
}