// Name     :   Muhammad Bin Nasir
// Reg no   :   220201012

// Code for Double Sided Queue in linear manner.
// It is a simple queue, with pointers named Left and Right instead of Front
// and Rear. The queue can be enqueued and dequeued from both sides, and 
// hence, we have to take care of both sides for empty and full queue.

// I have put Left = 0 and Right = 1, so that the two pointers do not overlap,
// because both can enqueue. If both point to same index, one will overright the
// other. So I have modified the queue, so that it will show empty when left and
// right ptrs  are adjacent (queue is empty).

#include <iostream>
using namespace std;

class intQueue
{
    private:

    int *myQueue;
    int left;
    int right;
    int Size;

    public:

    intQueue(int size)
    {
        myQueue = new int[size];
        Size = size;
        left = 0;
        right  = 1;
    }    


    void rightEnqueue(int a)
    {
        if (!isfull() && right != Size+1)
        {
            myQueue[right] = a;
            right++;
        }
        else
        {
            cout<<"Queue overflow\n";
        }
    }
    
    void leftEnqueue(int a)
    {
        if (!isfull() && left != -1)
        {
            myQueue[left] = a;
            left--;
        }
        else
        {
            cout<<"Queue overflow\n";
        }
    }    


    int rightDequeue()
    {
        if (!isempty() && right-left!=1)
        {
            return myQueue[right--];
        }
        else
        {
            cout<<"Queue Underflow"<<endl;
        }
    }

    int leftDequeue()
    {
        if (!isempty() && right-left!=1)
        {
            return myQueue[left++];
        }
        else
        {
            cout<<"Queue Underflow"<<endl;
        }
    }

    bool isfull()
    {
        if (right == Size+1 && left == 0)
        {
            return true;
        }
        return false;
    }


    bool isempty()
    {
        if (right - left ==1)
        {
            return true;
        }
        return false;
    }


    int size()
    {
        return right-left-1;
    }


    int leftPeek()
    {
        return myQueue[left];
    }

    int rightPeek()
    {
        return myQueue[right];
    }    

    void display()
    {
        cout<<"{ ";
        for (int i=left+1;i<right;i++)
        {
            cout<<myQueue[i]<<" ";
        }
        cout<<"}"<<endl;
    }
};

int main()
{
    intQueue q1(5);

    q1.rightEnqueue(1);
    q1.rightEnqueue(2);
    q1.rightEnqueue(3);
    q1.rightEnqueue(4);
    q1.rightEnqueue(5);

    q1.display();

    q1.leftEnqueue(20);

    q1.leftDequeue();

    q1.display();

    q1.rightDequeue();

    q1.display();
}