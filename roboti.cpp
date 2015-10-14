#include <climits>
#include <vector>

using namespace std;

#define INT_MAX 1<<27

void FloydWarshall (int number_of_vertexes, int number_of_edges, vector<vector<int> > &lengths_solution_label0, vector<vector<int> > &lengths_solution_label1, vector<vector<int> > &lengths_solution_label2, const vector<vector<int> > &graph_matrix)
{
    for (int i = 0; i < number_of_vertexes; i++)
        lengths_solution_label0[i][i] = 0;
    for (int i = 0; i < number_of_edges; i++)
    {
        if (graph_matrix[i][2] < lengths_solution_label0[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] && graph_matrix[i][2] % 3 == 0) lengths_solution_label0[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] = graph_matrix[i][2];
        if (graph_matrix[i][2] < lengths_solution_label1[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] && graph_matrix[i][2] % 3 == 1) lengths_solution_label1[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] = graph_matrix[i][2];
        if (graph_matrix[i][2] < lengths_solution_label2[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] && graph_matrix[i][2] % 3 == 2) lengths_solution_label2[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] = graph_matrix[i][2];
    }
    for (int k = 0; k < number_of_vertexes; k++)
        for (int i = 0; i < number_of_vertexes; i++)
            for (int j = 0; j < number_of_vertexes; j++)
            {
                if(lengths_solution_label0[i][k] + lengths_solution_label0[k][j] < lengths_solution_label0[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label0[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label0[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label0[k][j] < lengths_solution_label1[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label0[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label0[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label0[k][j] < lengths_solution_label2[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label0[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label0[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label1[k][j] < lengths_solution_label0[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label1[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label0[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label1[k][j] < lengths_solution_label1[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label1[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label0[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label1[k][j] < lengths_solution_label2[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label1[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label0[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label2[k][j] < lengths_solution_label0[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label2[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label0[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label2[k][j] < lengths_solution_label1[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label2[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label0[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label2[k][j] < lengths_solution_label2[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label2[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label0[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label0[k][j] < lengths_solution_label0[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label0[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label1[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label0[k][j] < lengths_solution_label1[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label0[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label1[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label0[k][j] < lengths_solution_label2[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label0[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label1[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label1[k][j] < lengths_solution_label0[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label1[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label1[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label1[k][j] < lengths_solution_label1[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label1[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label1[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label1[k][j] < lengths_solution_label2[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label1[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label1[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label2[k][j] < lengths_solution_label0[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label2[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label1[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label2[k][j] < lengths_solution_label1[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label2[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label1[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label2[k][j] < lengths_solution_label2[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label2[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label1[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label0[k][j] < lengths_solution_label0[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label0[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label2[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label0[k][j] < lengths_solution_label1[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label0[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label2[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label0[k][j] < lengths_solution_label2[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label0[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label2[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label1[k][j] < lengths_solution_label0[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label1[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label2[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label1[k][j] < lengths_solution_label1[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label1[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label2[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label1[k][j] < lengths_solution_label2[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label1[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label2[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label2[k][j] < lengths_solution_label0[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label2[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label2[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label2[k][j] < lengths_solution_label1[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label2[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label2[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label2[k][j] < lengths_solution_label2[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label2[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label2[i][k] + lengths_solution_label2[k][j];
            }
}

int Paths (int remainder, int lower_bound, int upper_bound, int number_of_vertexes, int number_of_edges, const vector<vector<int> > &graph_matrix)
{
    vector<vector<int> > lengths_solution_label0 (number_of_vertexes, vector<int>(number_of_vertexes, INT_MAX)), lengths_solution_label1 (number_of_vertexes, vector<int>(number_of_vertexes, INT_MAX)), lengths_solution_label2 (number_of_vertexes, vector<int>(number_of_vertexes, INT_MAX));
    FloydWarshall (number_of_vertexes, number_of_edges, lengths_solution_label0, lengths_solution_label1, lengths_solution_label2, graph_matrix);
    int counter (0);
    if (remainder == 0)
    {
        for (int i = 0; i < number_of_vertexes; i++)
            for (int j = 0; j < number_of_vertexes; j++)
                if (lengths_solution_label0[i][j] >= lower_bound && lengths_solution_label0[i][j] <= upper_bound) counter++;
    }
    if (remainder == 1)
    {
        for (int i = 0; i < number_of_vertexes; i++)
            for (int j = 0; j < number_of_vertexes; j++)
                if (lengths_solution_label1[i][j] >= lower_bound && lengths_solution_label1[i][j] <= upper_bound) counter++;
    }
    if (remainder == 2)
    {
        for (int i = 0; i < number_of_vertexes; i++)
            for (int j = 0; j < number_of_vertexes; j++)
                if (lengths_solution_label2[i][j] >= lower_bound && lengths_solution_label2[i][j] <= upper_bound) counter++;
    }
    return counter;
}

int BrojMinimalnihPotrosnji(int r, int p, int q, int v, int e, int* energije)
{
    vector<vector<int> > graph_matrix(e, vector<int>(3));
    for (int i = 0; i < e * 3; i += 3)
    {
        graph_matrix[i / 3][0] = energije[i];
        graph_matrix[i / 3][1] = energije[i + 1];
        graph_matrix[i / 3][2] = energije[i + 2];
    }
    return Paths (r, p, q, v, e, graph_matrix);
}
