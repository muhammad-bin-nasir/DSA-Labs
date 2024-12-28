// Display in inorder, preorder, postorder
// Node deletion methods to study
// Search something in a tree

#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node ()
    {
        data = 0;
        right = NULL;
        left = NULL;
    }

    Node (int value)
    {
        data = value;
        right = NULL;
        left = NULL;
    }
};

class Tree
{
    private:
    Node* root;

    void insert (int val,Node*& node)
    {
        if (node == NULL)
        {
            node = new Node (val);
        }

        else if (val <= node->data)
        {
            insert (val,node->left);
        }

        else
        {
            insert (val,node->right);
        }
    }

    void displayPreA (Node* node)
    {
        if (node != NULL)
        {
            cout<<node->data<<" ";
            displayPreA(node->left);
            displayPreA(node->right);
        }
    }

    void displayInA (Node* node)
    {
        if (node != NULL)
        {
            displayInA(node->left);
            cout<<node->data<<" ";
            displayInA(node->right);
        }
    }

    void displayPostA (Node* node)
    {
        if (node != NULL)
        {
            displayPostA(node->left);
            displayPostA(node->right);
            cout<<node->data<<" ";
        }
    }       

    bool search(int val, Node* node) 
    {
        if (node == NULL)
        {
            return false;
        }        
        else if (val > node->data)
        {
            return search(val,node->right);
        }
        else if (val < node->data)
        {
            return search(val, node->left);
        }
        else if (val == node->data)
        {
            return true;
        }
    }


    public:
    Tree ()
    {
        root = NULL;
    }

    void AddValue(int val)
    {
        insert (val,root);
    }


    void DisplayPreorder()
    {
        displayPreA(root);
    }

    void DisplayPostorder()
    {
        displayPostA(root);
    }

    void DisplayInorder()
    {
        displayInA(root);
    }    

    bool Search(int val)
    {
        search(val,root);
    }

};

int main()
{
    Tree t;
    int x;
    t.AddValue(5);
    t.AddValue(2);
    t.AddValue(3);
    t.AddValue(6);
    t.AddValue(7);
    t.AddValue(1);
    t.AddValue(4);
    t.AddValue(9);
    t.AddValue(8);
    t.AddValue(0);

    t.DisplayPreorder();
    cout<<endl;
    t.DisplayPostorder();
    cout<<endl;
    t.DisplayInorder();
    cout<<endl;


    cout<<"Give value to seaarch: "<<endl;
    cin>>x;
    cout<<t.Search(x);
}