#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

#define B (*this);

class Number
{
public:

    deque <int> digits;
    
    Number() { }
    
    void Input()
    {
        char c;
        while (!(isdigit (c = getchar())));
        digits.push_front (c - '0');
        while (isdigit (c = getchar())) digits.push_front (c - '0');
    }    
    
    int Size()
    {
        return digits.size();
    }    
    
    void Print()
    {
        int s = Size();
        for (int i = s - 1; i >= 0; i--)
        {
            printf ("%d", digits [i]);
        }     
    }    
    
    void Reverse()
    {
        reverse (digits.begin(), digits.end());
    }    
    
    int &operator + (const int index)
    {
        return digits [index];
    }   
    
    void Push (int number)
    {
        digits.push_back (number);
    }    
    
    void operator += (const Number &B)
    {
        int prijenos = 0;
        for (int i = 0; i < min (A.Size(), B.Size()); i++)
        {
            A [i] = (prijenos + A [i] + B [i]) % 10;
            prijenos = (prijenos + A [i] + B [i]) / 10;
        }  
        
        if (A.Size() < B.Size())
        {  
            for (int i = A.Size(); i < B.Size(); i++)
            {
                A.Push ((prijenos + A [i]) % 10);
                prijenos = (prijenos + A [i]) / 10;
            }    
        }  
        else if (A.Size() > B.Size())
        {
            for (int i = B.Size(); i < A.Size(); i++)
            {
                
            } 
        }          
        if (prijenos > 0) A.Push (prijenos);
        
        return;
    }    
};
    
int main ()
{
    Number a, b;
    a.Input();
    b.Input();
    
    a += b;
    
    a.Print(); printf ("\n");
    b.Print(); printf ("\n");
    
    
    
    system ("pause");
    return 0;
}    

















