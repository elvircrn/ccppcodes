#include <iostream>
#include <stack>

using namespace std;

stack<char>digit_stack;
stack<char>operator_stack;
stack<int>addition_stack;

int bitnost(char a)
{
    int temp;
    if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 3;
    return temp;
}

int main()
{
    string mandza;
    string infix_string;
    string postfix_string;
    cin>>infix_string;

    for(int i=0; i<infix_string.length(); i++)
    {
        if(infix_string[i]=='+' || infix_string[i]=='-' || infix_string[i]=='*' || infix_string[i]=='/')
        {
            while(!operator_stack.empty() && bitnost(operator_stack.top())<=bitnost(infix_string[i]))
            {
                postfix_string+=operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(infix_string[i]);
        }

        else postfix_string+=infix_string[i];

        if(isdigit(infix_string[i])) digit_stack.push(infix_string[i]);
    }

    while(!operator_stack.empty())
    {
        postfix_string+=operator_stack.top();
        operator_stack.pop();
    }

    cout<<postfix_string;

    return 0;
}
