Mirko loves cars and he finally managed to start his own car factory! Factory has N employees, each of them has exactly one superior (except Mirko - he is by default everybody’s superior). Mirko is denoted by number 1, and the rest of the employees with numbers 2 to N.
Every employee can raise or lower the wages of all of his subordinates (both direct subordinates and those lower in the hieararchy tree). Mirko’s role is to prevent abuse of such power, so from time to time he wants to know wage of a particular employee.
He is asking you to write a program which will help him monitor wage changes, given a sequence of commands described in the input section.
Remark: at any time, all of the wages will be positive integers and will fit in standard 32-bit integer type (int in C/C++, longint in Pascal).
INPUT:
First line of input contains two space-separated positive integers N (1 ≤ N ≤ 500 000), number of employees, and M (1 ≤ M ≤ 500 000), number of wage changes and wage queries.
Next N lines contain the information about employees 1, 2, ..., N(respectively): starting wage and the identifier of his direct supervisor. Remark: Mirko has no supervisor, so his line will contain only his starting wage.
Next M lines contain one of the following:
1. p A X - employee A increases (or decreases in case of a negative X) wage of all his subordinates by the amount X (-10 000 ≤ X ≤ 10 000);
2. u A - Mirko wants to know the wage of employee A.

OUTPUT:
Output should contain one line for each ‘2’ query in the input - the current wage of the given employee.

Input:
2 3
5
3 1
p 1 5
u 2
u 1
Output:
8
5
Input:
5 5
4
2 1
6 1
7 1
3 4
u 3
p 1 -1
u 3
p 4 5
u 5
Output:
6
5
7
Input:
6 7
5
4 1
3 2
7 3
2 3
3 5
p 3 2
p 2 4
u 3
u 6
p 5 -2
u 6
u 1
Output:
7
9
7
5
