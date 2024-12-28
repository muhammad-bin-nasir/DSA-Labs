#include <iostream>
using namespace std;


class newStack
{
    int *arr;
    int top;

    public:

    newStack(int size)
    {
        arr = new  int[size];
        top = -1;
    }

    void Push(int x)
    {
        arr[++top] = x;
    }

    void Pop()
    {
        top--;
    }

    int Top()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        if (top==-1)
            return true;
        return false;
    }
};

void DecToBin(int x)
{
    newStack s1(10);
    while (x>0)
    {
        s1.Push(x%2);
        x = x/2;
    }

    while (!s1.isEmpty())
    {
        cout<<s1.Top();
        s1.Pop();
    }

} 

int main()
{
    int num;
    cout<<"What number to convert?"<<endl;
    cin>>num;
    DecToBin(num);

}