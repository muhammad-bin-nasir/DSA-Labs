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
			head = n1;
		}
		else
		{
			Node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n1;
			
		}
	}
	
	void printList()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout<<temp->data<<"  ";
			temp = temp->next;
		}
	}
	
	void insertfront(int n)
	{
		Node *n1 = new Node(n);
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
		while (temp->next != NULL && count!=index-1)
		{
			count++;
			temp = temp->next;
		}
		n1->next = temp->next;
		temp->next = n1;
	}

	void Sort()
	{
		Node *temp = head;
		int count = 0;
		while (temp->next != NULL)
		{
			count++;
			temp = temp->next;
		}
		temp = head;

		for (int i=0;i<count;i++)
		{
			while (temp->next != NULL)
			{
				if (temp->data > temp->next->data)
				{
					int var = temp->data;
					temp->data = temp->next->data;
					temp->next->data = var;
				}
				temp = temp->next;
			}
			temp = head;
		}
	}

	void DescendingSort()
	{
		Node *temp = head;
		int count = 0;
		while (temp->next != NULL)
		{
			count++;
			temp = temp->next;
		}
		temp = head;

		for (int i=0;i<count;i++)
		{
			while (temp->next != NULL)
			{
				if (temp->data < temp->next->data)
				{
					int var = temp->data;
					temp->data = temp->next->data;
					temp->next->data = var;
				}
				temp = temp->next;
			}
			temp = head;
		}
	}	

	void SearchandFound(int x)
	{
		LinkedList l1;
		Node*temp = head;
		int count = 0;
		int index = 0;
		while (temp->next != NULL)
		{
			if (temp->data == x)
			{
				count++;
				l1.insertend(index);
			}
			temp = temp->next;
			index++;
		}
		if (count == 0)
		{
			cout<<"Element not found.";
		}
		else
		{
			cout<<"Element "<<x<<" is present "<<count<<" times at indexes: ";
			Node *temp = l1.head;
			while (temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
	}
		
	
};

int main()
{
	LinkedList l1;
	int search;

	l1.insertend(5);
	l1.insertend(6);
	l1.insertend(7);
	l1.insertend(5);
	l1.insertend(6);
	l1.insertend(7);
	l1.insertend(5);
	l1.insertend(6);
	l1.insertend(7);	
	l1.insertend(2);	

	l1.printList();
	cout<<endl;

	l1.Sort();
	cout<<"\nSorted list is: ";
	l1.printList();
	cout<<endl;
	
	l1.DescendingSort();
	cout<<"\nReverse sorted list is: ";
	l1.printList();
	cout<<endl;

	cout<<"\nWhat to find?\n";
	cin>>search;

	l1.SearchandFound(search);
	return 0;
}
