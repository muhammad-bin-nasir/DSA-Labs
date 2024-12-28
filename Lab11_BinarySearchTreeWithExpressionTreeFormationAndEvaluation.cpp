// Display in inorder, preorder, postorder
// Node deletion methods to study
// Search something in a tree

#include <iostream>
using namespace std;

class char_Stack
{
    public:
    int top;
    char mystack[10];

    char_Stack()
    {
        top = -1;
    }

    void push(char e)
    {
        if (top==10)
        {
            cout<<"Stack Overflow\n";
        }
        else
        {
            mystack[++top] = e;
        }
    }

    char pop()
    {
        if (top<0)
        {
            cout<<"Stack underflow\n";
        }
        else
        {
            return mystack[top--];
        }
    }

    char Top()
    {
        return mystack[top];
    }
};


class Node
{
    public:
    char data;
    Node* left;
    Node* right;
    
    Node ()
    {
        data = NULL;
        right = NULL;
        left = NULL;
    }

    Node (char value)
    {
        data = value;
        right = NULL;
        left = NULL;
    }
};


class NodeStack
{
    Node **mystack;
    int top;

    public:
    NodeStack(int size)
    {
        mystack = new Node*[size];
        top = -1;
    }

    void push(Node* New)
    {
        if (top==10)
        {
            cout<<"Stack Overflow\n";
        }
        else
        {
            mystack[++top] = New;
        }
    }

    Node* pop()
    {
        if (top<0)
        {
            cout<<"Stack underflow\n";
        }
        else
        {
            return mystack[top--];
        }
    }

    Node* Top()
    {
        return mystack[top];
    }
};   

Node* ExpressionTree(string exp)
{
    NodeStack s1(10);
    for (int i=0;i<exp.length();i++)
    {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/')
        {
            Node* n = new Node(exp[i]);
            s1.push(n);
        }
        else
        {
            Node* n = new Node(exp[i]);
            n->right = s1.pop();
            n->left = s1.pop();
            s1.push(n);
        }
    }
    return s1.pop();
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




string infixToPostfix(string infix)
{
    char_Stack s1;
    string postfix = "";
    int len = infix.size();
    for (int i=0;i<len;i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if (infix[i] == '+' || infix[i] == '-')
            {
                while (s1.Top() != '(' && s1.top >=0)
                {
                    postfix.append(string(1,s1.pop()));
                }
                s1.push(infix[i]);
            }

            if (infix[i] == '*' || infix[i] == '/')
            {
                while (s1.Top() == '*' || s1.Top() == '/')
                    postfix.append(string(1,s1.pop()));
                s1.push(infix[i]);                
            }
        }

        else if (infix[i] == '(')
        {
            s1.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (s1.Top() != '(' && s1.top >= 0)
            {
                postfix.append(string(1,s1.pop()));
            }
            s1.pop();
        }
        else
        {
            postfix.append(string(1,infix[i]));
        }
    }
    while (s1.top >= 0)
    {
        postfix.append(string(1,s1.pop()));
    }

    return postfix;
}

int numb(char num)
{
    if (num=='0')
        return 0;
    if (num=='1')
        return 1;
    if (num=='2')
        return 2;
    if (num=='3')
        return 3;
    if (num=='4')
        return 4;
    if (num=='5')
        return 5;
    if (num=='6')
        return 6;
    if (num=='7')
        return 7;
    if (num=='8')
        return 8;
    if (num=='9')
        return 9;
}

int ExpressionEvaluation (Node *n)
{
    if (n->data != '+' && n->data != '-' && n->data != '*' && n->data != '/')
    {
        return numb(n->data);
    }
    else
    {
        if (n->data == '*')
            return ExpressionEvaluation(n->left) * ExpressionEvaluation(n->right);
        if (n->data == '+')
            return ExpressionEvaluation(n->left) + ExpressionEvaluation(n->right);
        if (n->data == '-')
            return ExpressionEvaluation(n->left) - ExpressionEvaluation(n->right);
        if (n->data == '/')
            return ExpressionEvaluation(n->left) / ExpressionEvaluation(n->right); 
    }
}

int main()
{
    string s = "2+(5-2)*4";

    s = infixToPostfix(s);
    Node* n = ExpressionTree(s);
    displayInA(n);
    cout<<endl;
    displayPostA(n);
    cout<<endl;
    displayPreA(n);
    cout<<endl;
    cout<<ExpressionEvaluation(n);
}
