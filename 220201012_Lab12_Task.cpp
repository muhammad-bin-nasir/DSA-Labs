#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        next = NULL;
        prev = NULL;
    }
    
    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
    private:
    Node *head;
    Node *tail;

    public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insertFront(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() const
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void BubbleSort()
    {
        Node *temp1 = head;
        while (temp1 != NULL)
        {
            Node *temp2 = temp1->next;
            while (temp2 != NULL)
            {
                if (temp1->data > temp2->data)
                {
                    int temp = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = temp;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
    // Insertion Sort
    void InsertionSort()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *sorted = NULL;
        Node *current = head;

        while (current != NULL)
        {
            Node *nextNode = current->next;

            if (sorted == NULL || sorted->data > current->data)
            {
                current->next = sorted;
                current->prev = NULL;
                if (sorted != NULL)
                    sorted->prev = current;
                sorted = current;
            }
            else
            {
                Node *temp = sorted;
                while (temp->next != NULL && temp->next->data < current->data)
                {
                    temp = temp->next;
                }

                current->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = current;

                temp->next = current;
                current->prev = temp;
            }

            current = nextNode;
        }

        head = sorted;
    }

    // Selection Sort
    void SelectionSort()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *minNode = current;
            Node *temp = current->next;

            while (temp != NULL)
            {
                if (temp->data < minNode->data)
                {
                    minNode = temp;
                }
                temp = temp->next;
            }

            // Swap current and minNode data
            swap(current->data, minNode->data);

            current = current->next;
        }
    }
};

int main()
{
    // Bubble sorting
    DoublyLinkedList BubbleList;
    BubbleList.insertEnd(4);
    BubbleList.insertEnd(2);
    BubbleList.insertEnd(1);
    BubbleList.insertEnd(9);
    BubbleList.insertEnd(7);
    BubbleList.insertEnd(5);

    cout << "Doubly Linked List of Integers: ";
    BubbleList.display();

    BubbleList.BubbleSort();

    cout << "Doubly Linked List of Integers after bubble sort: ";
    BubbleList.display();


    
    // Insertion Sorting
    DoublyLinkedList InsertionList;
    InsertionList.insertEnd(4);
    InsertionList.insertEnd(2);
    InsertionList.insertEnd(1);
    InsertionList.insertEnd(9);
    InsertionList.insertEnd(7);
    InsertionList.insertEnd(5);

    cout << "Doubly Linked List of Integers: ";
    InsertionList.display();

    InsertionList.InsertionSort();

    cout << "Doubly Linked List of Integers after Insertion sort: ";
    InsertionList.display();

    
    // Selection Sorting
    DoublyLinkedList SelectionList;
    SelectionList.insertEnd(4);
    SelectionList.insertEnd(2);
    SelectionList.insertEnd(1);
    SelectionList.insertEnd(9);
    SelectionList.insertEnd(7);
    SelectionList.insertEnd(5);

    cout << "Doubly Linked List of Integers: ";
    SelectionList.display();

    SelectionList.SelectionSort();

    cout << "Doubly Linked List of Integers after Insertion sort: ";
    SelectionList.display();
    
    return 0;
}