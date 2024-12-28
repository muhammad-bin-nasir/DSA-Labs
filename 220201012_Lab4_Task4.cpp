// Name     :    Muhammad Bin Nasir
// Reg no   :    220201012

// In this program, I have done 3 main things using Queues:
// 1. Check for consecutive duplicates in a user provided string.
// 2. Reverse a given string using Queues.
// 3. Count each character in a given string.

#include <iostream>
#define size 30

using namespace std;

// We make a class for Queue, with basic functions of Enqueue, Dequeue, isEmpty and isFull.

class Queue
{
    public:

    char que[size];
    int front;
    int rear;

    Queue()
    {
        front = 0;
        rear  = 0;
    }    

// Enque adds an element to the rear of the queue, and increments the rear pointer,
// but if rear points to the end and queue is not full, it loops it back to start, because queue is circular.

    void enque(char a)
    {
        if (!isfull())
        {
            que[rear] = a;
            if (rear < size)
            {
                rear++;
            }
            else
            {
                rear = 0;
            }
        }
        else
        {
            cout<<"\nQueue overflow\n";
        }
    }

// Dequeue removes an element from front of the queue, and increments the front pointer,
// but if front points to the end, it loops it back to start.

    char deque()
    {
        if (!isempty())
        {
            return que[front++];
        }
        else
        {
            cout<<endl<<"Queue Underflow"<<endl;
        }
    }

// isFull returns if Queue is full by checking if the rear pointer and front pointer difference is size or -1, because queue
// is circular.

    bool isfull()
    {
        if (rear - front == size || front - rear == 1)
        {
            return true;
        }
        return false;
    }

// isEmpty checks if queue is empty by checking if both pointers point to the same spot.    

    bool isempty()
    {
        if (rear == front)
        {
            return true;
        }
        return false;
    }

// Size funtion returns the number of elements in the queue

    int Size()
    {
        return rear-front;
    }

// Peek function shows the front value of queue without removing it.

    void peek()
    {
        cout<<"\nElement at peek is: "<<que[front];
    }

};

// checkDuplicate works by pushing the characters of a string in a queue, and then calls them in an array.
// If two entries of the array are duplicated, it outputs the index of the repetetion.
// If no duplication, it outputs a message saying so.

void checkDuplicate(string s)
{
    Queue q1;
    char array[s.length()];
    int count = 0; 

    for (int i=0;i<s.length();i++)
    {
        q1.enque(s[i]);
    }    
    
    int Size = q1.Size();

    for (int i=0;i<Size;i++)
    {
        array[i] = q1.deque();
        if (array[i] == array[i-1])
        {
            cout<<"Character "<<array[i]<<" is duplicated at index "<<i-1<<" and "<<i<<endl;
            count += 1;
        }
    }
    if (count == 0)
    {
        cout<<"No consecutive letters are being repeated."<<endl;
    }

}

// reverseString function works by recieving a string, and then pushing it in a queue. It then recalls the
// string characters from queue, and inserts them at index [0], pushing previous string forwards, hence reversing
// the string.

string reverseString(string s)
{
    Queue q1;
    string newString;

    for (int i=0;i<s.length();i++)
    {
        q1.enque(s[i]);
    }
    
    for (int i=0;i<s.length();i++)
    {
        newString.insert(0,string(1,q1.deque()));
    }

    return newString;
}

// countCharacters function works by taking a string, converting it to uppercase (both to eliminate the case sensitivity,
// and to use the ASCII codes for indices) and then pushing it in a queue. We have also made two arrays, one with all
// alphabets in order, to easily find the alphabet using index, and another with the frequency of an alphabet at given
// index. Then a while loop is run until queue is not empty, and queue is dequeued. Index of each element is found using
// ASCII codes by " char - 'A' " method. Then the value at resulting index is incremented. At the end, all the non-zero
// entries in the array with frequencies are outputed.

void countCharacters(string s)
{
    Queue q1;
    int alphabetCount [26] = {0};
    char Alphabets [26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    for (int i=0;i<s.length();i++)
    {
        if (isalpha(s[i]))
        {
            q1.enque(toupper(s[i]));
        }
    }

    while (!q1.isempty())
    {
        char temp = q1.deque();
        int index = temp - 'A';
        alphabetCount[index] = alphabetCount[index] + 1;
    }

    for (int i=0;i<26;i++)
    {
        if (alphabetCount[i] > 0)
        {
            cout<<"The alphabet "<<Alphabets[i]<<" occurs: "<<alphabetCount[i]<<" times."<<endl;
        }
    }


}


int main()
{
    // Program to check consecutive duplicate characters in a string

    string userString;
    
    cout<<"Please give your input: "<<endl;
    getline(cin,userString);

    checkDuplicate(userString);

    // Program to reverse a string using Queues

    string userString2;

    cout<<"Give a string to reverse: "<<endl;
    getline(cin,userString2);

    cout<<"The reversed string is: "<<reverseString(userString2)<<endl;

    // Count the alphabets

    string userString3;

    cout<<"Please give a string to count the alphabets"<<endl;
    getline(cin,userString3);

    countCharacters(userString3);

    return 0;
}