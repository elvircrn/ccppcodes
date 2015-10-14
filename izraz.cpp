#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <cctype>
#include <sstream>

using namespace std;

int get_pos (char op)
{
    return ((op == '*' || op == '/') ? 1 : 2);
}

int process (int a, char op, int b)
{
    if (op == '*')
        return a * b;
    else if (op == '/')
        return b / a;
    else if (op == '+')
        return a + b;
    else if (op == '-')
        return b - a;
}

struct element
{
    char op;
    int number;

    element () { op = 0; number = -1; }
    element (char _op) { op = _op; number = -1; }
    element (int _number) { number = _number; op = 0; }

    void print()
    {
        if (op)
            putchar (op);
        else
            printf ("%d", number);
    }
};

stack <char> operators;
vector <element> elements;

int izracunaj(const char *izraz) {

    int current_number = 0, len = strlen (izraz);

    for (int i = 0; i < len; i++)
    {
        if (!isdigit (izraz [i]) && current_number != 0)
        {
            elements.push_back (current_number);
            current_number = 0;
        }

        if (izraz [i] == '(')
            operators.push (izraz [i]);
        else if (izraz [i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                elements.push_back (operators.top());
                operators.pop();
            }

            if (operators.empty() == false)
                operators.pop();
        }
        else if (izraz [i] == '+' || izraz [i] == '-' || izraz [i] == '*' || izraz [i] == '/')
        {
            while (!operators.empty() && get_pos (izraz [i]) >= get_pos (operators.top()))
            {
                if (operators.top() == '(')
                    break;
                elements.push_back (element (operators.top()));
                operators.pop();
            }

            operators.push (izraz [i]);

            current_number = 0;
        }
        else if (isdigit (izraz [i]))
            current_number = ((current_number * 10) + (izraz [i] - '0'));
    }


    if (current_number > 0)
        elements.push_back (element (current_number));


    while (!operators.empty())
    {
        elements.push_back (element (operators.top()));
        operators.pop();
    }

    stack <int> solution;

    for (int i = 0; i < elements.size(); i++)
    {
        if (elements [i].op)
        {
            int A = solution.top();
            solution.pop();
            int B = solution.top();
            solution.pop();

            solution.push (process (A, elements [i].op, B));
        }
        else
            solution.push (elements [i].number);
    }

    return solution.top();
}


