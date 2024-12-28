#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	
	Node()
	{
		data = 0;
		next = NULL;
	}	
	
	Node(int a)
	{
		data = a;
		next = NULL;
	}	
	
	void insert(int a)
	{
		data = a;
	}
	
	void Next(Node a)
	{
		next = &a;
	}
		
};

class LinkedList
{
	public:
	Node *head;
	
	LinkedList()
	{
		head = NULL;
	}
	void insertend(int n)
	{
		Node *n1 = new Node(n);
		if (head == NULL)
		{
			cout<<"Head initialised..."<<endl;
			head = n1;
            n1->next = head;
		}
		else
		{
			Node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n1;
            n1->next = head;
			cout<<"Node added..."<<endl;
			
		}
	}
	
	void printList()
	{
		Node *temp = head;
		do
		{
			cout<<temp->data<<"  ";
			temp = temp->next;
		}
        while (temp != head);
	}
	
	void insertfront(int n)
	{
        Node *n1 = new Node(n);
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n1;
        n1->next = head;
        head = n1;
			
	
	
	}
	
	void insertafter(int n,int index)
	{
		Node *n1 = new Node(n);
		Node *temp = head;
		int count = 0;
		while (temp->next != NULL)
		{
			count++;
			temp = temp->next;
			if (count==index)
				break;
		}
		n1->next = temp->next;
		temp->next = n1;
	}
	
	void insertbefore(int n,int index)
	{

		Node *n1 = new Node(n);
		Node *temp = head;
		int count = 0;
		while (temp->next != NULL && count!=index-2)
		{
			count++;
			temp = temp->next;
		}
		n1->next = temp->next;
		temp->next = n1;
	}

	void insert(int n,int index)
	{

		Node *n1 = new Node(n);
		Node *temp = head;
		int count = 0;
		do
		{
			count++;
			temp = temp->next;
		}
        while (temp->next != NULL && count!=index-2);
		n1->next = temp->next;
		temp->next = n1;
	}
		
	
};

int main()
{
	LinkedList l1;
	l1.insertend(5);
	l1.insertend(6);
	l1.insertend(7);
	l1.printList();
	cout<<endl;
	
	l1.insertfront(3);	
	l1.printList();
	cout<<endl;
	
	l1.insertafter(3,2);
	l1.printList();
	cout<<endl;
	
	l1.insertbefore(3,2);
	l1.printList();
}
