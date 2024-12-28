// Name     :   Muhammad Bin Nasir
// Reg no   :   220201012
// Batch    :   CS-03

// The logic used to evaluate the infix expression is, we first convert the 
// Infix expression to postfix one, and the evaluate it.


#include <iostream>
using namespace std;

// First we make two stacks, one of int type, and another of char type.
// with push, pop and Top functions. Pop and top differ by, that Pop removes 
// element along with returning it, while Top doesn't.


class int_Stack
{
    public:
    int top;
    int mystack[10];

    int_Stack()
    {
        top = -1;
    }

    void push(int e)
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

    int pop()
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

    int Top()
    {
        return mystack[top];
    }
};

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


// A function to check if given character is an operator.

bool isOperator(char check)
{
    switch (check)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        return true;
    }
    return false;
}


// A function to solve an operation between two operands and an operator.

int solveOperator(int a, int b, char c)
{
    if (c=='+')
    {
        return a+b;
    }
    if (c=='*')
    {
        return a*b;
    }
    if (c=='-')
    {
        return b-a;
    }
    if (c=='/')
    {
        return b/a;
    }            
}


// This function solves Postfix Notation using stack. The algorithm is:
// 1.   Run a loop on expression. If operand, push in the stack.
// 2.   If operator encountered, pop the top two values from stack,
//      and apply the operation.
// 3.   After completion, only one value should be left in stack, which is
//      the result.


int solvePostfix(string postfix)
{
    int_Stack s1;
    int temp1,temp2,temp3;
    int len = postfix.size();
    for (int i=0;i<len;i++)
    {
        if (isOperator(postfix[i]))
        {
            temp1 = s1.pop();
            temp2 = s1.pop();
            temp3 = solveOperator(temp1,temp2,postfix[i]);
            s1.push(temp3);
        }
        else
        {
            s1.push(postfix[i] - '0');
        }
    }
    return s1.pop();
}


// This function converts infix to postfix. The algorithm is:
// 1.   If operand, append to postfix string.
// 2.   If operator:
//          i) If "(", push to the stack.
//         ii) If operator, pop all operators of equal or lower 
//             precedence already in stack, and append to postfix string. Push
//             the said operator to the stack.
//        iii) If ")", pop all operators, until encountered with
//             "(". Append all operators to postfix string, and delete 
//             "(" and ")".

// Because the stack is of type char, and the input in string, there is 
// some typecasting done too.


string infixToPostfix(string infix)
{
    char_Stack s1;
    string postfix = "";
    int len = infix.size();
    for (int i=0;i<len;i++)
    {
        if (isOperator(infix[i]))
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


// The primary function called from the main.
// It calls both the functions from above.


int evaluate(string infix)
{
    string postfix = infixToPostfix(infix);
    int result = solvePostfix(postfix);
    return result;
}



int main()
{
    string infix;
    cout<<"Give the innput string to evaluate: "<<endl;
    cin>>infix;                         // Comment for automatic code
    
    //string infix = "2+3*4-1";         // Uncomment for automatic code
    
    int result = evaluate(infix);

    cout<<"The expression is: "<<infix<<endl;
    cout<<"The result of above expression is: "<<result;
    return 0;
}