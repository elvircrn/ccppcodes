#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n_boxes, n_dimensions;

struct Box
{
    vector <int> lengths;
    int original_index;

    Box() { }

    void get(int org)
    {
        original_index = org;
        lengths = vector<int>(n_dimensions);
        for (int i = 0; i < n_dimensions; i++)
            scanf ("%d", &lengths [i]);
        sort (lengths.begin(), lengths.end());
    }

    void print() const
    {
        for (int i = 0; i < n_dimensions; i++)
            printf ("%d ", lengths [i]);
        printf ("\n");
    }

    bool fits_in (const Box &B) const
    {
        for (int i = 0; i < n_dimensions; i++)
            if (lengths [i] >= B.lengths [i])
                return false;

        return true;
    }

    bool operator< (const Box &B) const
    {
        for (int i = 0; i < n_dimensions; i++)
            if (lengths [i] >= B.lengths [i])
                return false;

        return true;
    }

    int operator[] (const int index) const
    {
        return lengths [index];
    }
};

Box boxes [1000];
int dp [1000], parent [1000];
vector<int> solution_set;

int main()
{
    scanf ("%d %d", &n_boxes, &n_dimensions);
    for (int i = 0; i < n_boxes; i++)
        boxes [i].get(i + 1);

    for (int i = 0; i < n_boxes; i++)
        for (int j = i + 1; j < n_boxes; j++)
            if (!boxes [i].fits_in (boxes [j]))
                swap (boxes [i], boxes [j]);

    for (int i = 0; i < n_boxes; i++)
        boxes [i].print();

    /*parent [0] = 0;
    dp [0] = 1;
    int solution = 1, start_index;

    for (int i = 1; i < n_boxes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (boxes [j].fits_in (boxes [i]) && dp [j] + 1 > dp [i])
            {
                dp [i] = dp [j] + 1;
                parent [i] = j;
            }
        }
        if (solution < dp [i])
        {
            start_index = i;
            solution = dp [i];
        }
    }

    printf ("%d\n", solution);

    int current_index = start_index;

    while (parent [current_index] != current_index)
    {
        solution_set.push_back (boxes [current_index].original_index);
        current_index = parent [current_index];
    }
    for (int i = 0; i < solution_set.size(); i++)
        printf ("%d ", boxes [i].original_index);
    printf ("%d\n", boxes [start_index].original_index);*/

    return 0;
}
/*
2 2
1 2
1 1


5 2
3 7
8 10
5 2
9 11
21 18
*/
