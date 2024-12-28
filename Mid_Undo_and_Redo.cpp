#include <iostream>
using namespace std;

// Task 1: A basic application of text editor demonstrating implementation of stack or maybe a queue. User
// gives a text. Implement undo and redo functions.

class Stack2
{
    char *arr;
    int top;
    int size;

public:
    Stack2(int Size)
    {
        arr = new char[Size];
        top = -1;
        size = Size;
    }
    void Push(char val)
    {

        arr[++top] = val;
    }
    void Pop()
    {
        if (!isEmpty())
            top--;
        else
        {
            cout << "\nStack is Empty.";
        }
    }
    char Top()
    {
        if (!isEmpty())
            return arr[top];
        return -1;
    }
    void Print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << "";
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
};

int main()
{
    Stack2 Undo2(2000);
    Stack2 Redo2(2000);
    string val2;
    int check;
    int check2;

    cout << "Give your string: " << endl;
    getline(cin, val2);
    for (int i = 0; i < val2.length(); i++)
    {
        Undo2.Push(val2[i]);
    }

    cout << "Press 1 to Undo, and 2 to Redo.";
    while (true)
    {
        cin >> check;
        if (check == 1)
        {
            if (!Undo2.isEmpty())
            {
                Redo2.Push(Undo2.Top());
                Undo2.Pop();
                Undo2.Print();
            }
            else
                cout << "Can not Undo. Write something first." << endl;
        }
        else if (check == 2)
        {
            if (!Redo2.isEmpty())
            {
                Undo2.Push(Redo2.Top());
                Redo2.Pop();
                Undo2.Print();
            }
            else
                cout << "Can not Redo. Undo something first." << endl;
        }
        else
        {
            cout << "Wrong input.";
        }
        cout << endl
             << "Press 1 to Undo, and 2 to Redo.";
    }
}