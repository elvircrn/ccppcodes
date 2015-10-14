#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int n_elements = 111;

string elements[] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg" };
int n, len;
bool used [300] [300], found;
char compound [55];

vector <char> solution;

void dfs (int current_index)
{
    if (current_index == len)
    {
        found = true;
        return;
    }

    char current_element = toupper (compound [current_index]), next_element;

    if (current_index == len - 1)
    {
        if (used [current_element] [0])
        {
            solution.push_back (current_element);
            found = true;
            return;
        }
    }

    next_element = compound [current_index + 1];

    if (used [current_element] [0])
    {
        dfs (current_index + 1);
        if (found)
        {
            solution.push_back (current_element);
            return;
        }
    }

    if (used [current_element] [next_element])
    {
        dfs (current_index + 2);
        if (found)
        {
            solution.push_back (next_element);
            solution.push_back (current_element);
            return;
        }
    }
}

int main()
{
    for (int i = 0; i < n_elements; i++)
        if (elements [i].length() == 1)
            used [elements [i] [0]] [0] = 1;
        else
            used [elements [i] [0]] [elements [i] [1]] = 1;

    scanf ("%d", &n); getchar();
    for (int i = 0; i < n; i++)
    {
        gets (compound);
        len = strlen (compound);
        solution.clear();
        found = false;
        dfs (0);
        if (solution.size() == 0)
            printf ("0");
        else
            for (int j = solution.size() - 1; j > -1; j--)
                putchar (solution [j]);
        putchar ('\n');
    }

    return 0;
}

/*
2
3
4
5
*/




