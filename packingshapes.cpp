#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

#define MALO 1e-7

vector <string> solution;

class PackingShapes
{
public:
    double myabs(double a)
    {
        if (a < 0)
            return a * (-1);
        else
            return a;
    }

    bool cmp (double a, double b)
    {
        return myabs(a - b) < MALO;
    }

    bool less_equal(double a, double b)
    {
        return (a < b || cmp (a, b));
    }

    vector<string> tryToFit(int a, int b, vector <string> shapes)
    {
        solution.clear();
        string type;

        double A = a;
        double B = b;

        if (A < B)
            swap (A, B);

        double P, Q;
        for (int i = 0; i < shapes.size(); i++)
        {
            stringstream ss;
            ss.str(shapes [i]);
            ss>>type;

            if (type == "RECTANGLE")
            {
                ss>>P>>Q;
                if (P < Q)
                    swap (P, Q);
                if (A < B)
                    swap (A, B);


                if (less_equal (P, A) && less_equal (Q, B))
                {
                    solution.push_back ("YES");
                    continue;
                }
                else if (less_equal(P, A) || Q > B)
                {
                    solution.push_back ("NO");
                    continue;
                }

                double value = ((P + Q) / (A + B)) * ((P + Q) / (A + B)) +
                               ((P - Q) / (A - B)) * ((P - Q) / (A - B));

                if (A > P && less_equal (B, Q) && less_equal (2.0000000000, value))
                    solution.push_back ("YES");
                else
                    solution.push_back ("NO");
            }
            else
            {
                ss>>P;

                if (less_equal (P * 2.0000000000000f, (double)min (A, B)))
                    solution.push_back ("YES");
                else
                    solution.push_back ("NO");
            }
        }

        return solution;
    }
};

int one, two;

int main()
{
    one = 1;
    two = 2;
    vector <string> shapes;

    shapes.push_back ("RECTANGLE 577 192");

    PackingShapes asd;

    asd.tryToFit(535, 570, shapes);

    return 0;
}
