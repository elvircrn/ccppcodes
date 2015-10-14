#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

namespace CompetitiveProgramming
{
    #define RANGE_MIN 0
    #define RANGE_MAX 1
    #define INF 1<<30
    #define MIN 10e7

    class Math
    {
        public:

        static bool myAbs (float x)
        {
            if (x < 0)
                return x * (-1);
            else
                return x;
        }

        static bool equal (float x, float y)
        {
            return (myAbs (x - y) < MIN);
        }

        static int fast_pow (int base, int power, int mod)
        {
            if (power == 0)
                return 1;
            else if (power == 1)
                return base % mod;
            else if (power % 2 == 0)
            {
                int t = fast_pow (base, power / 2, mod) % mod;
                return (t * t) % mod;
            }
            else
                return ((fast_pow (base, power - 1, mod) % mod) * (base % mod) % mod);
        }
    };

    class Point2
    {
        public:

        float x, y;

        Point2 () { }
        Point2 (float _x, float _y) { x = _x; y = _y; }

        float distance (const Point2 &B) const
        {
            return sqrt ((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
        }

        static bool Collinear (const Point2 &A, const Point2 &B, const Point2 &C)
        {
            return true;
        }
    };

    template <class T>
    class BinarySearchTree
    {
        public:

        struct Node
        {
            T value;
            Node *left, *right;

            Node (T _value)
            {
                value = _value;
                left = NULL;
                right = NULL;
            }

            void GetValue() { return value; }
        };

        Node *root;

        BinarySearchTree() { root = NULL; }

        void Insert (const T &value)
        {
            Node *node = root, *previous = root;;

            if (root == NULL)
                root = new Node(value);
            else
            {
                while (node)
                {
                    previous = node;

                    if (value < node->value)
                        node = node->left;
                    else if (value > node->value)
                        node = node->right;
                }

                if (previous->value > value)
                    previous->left = new Node(value);
                else
                    previous->right = new Node(value);
            }
        }

        Node* GetRoot()
        {
            return root;
        }

        Node* Find (const T &value)
        {

        }
    };

    class UnionFindStructure
    {
        public:
        vector <int> parent;
        vector <int> sizes;

        UnionFindStructure() { }
        UnionFindStructure(int size)
        {
            parent = vector <int> (size + 5);
            sizes = vector <int> (size + 5);
            for (int i = 0; i <= size; i++)
            {
                sizes [i] = 1;
                parent [i] = i;
            }
        }

        void Reset(int size)
        {
            for (int i = 1; i <= size; i++)
                parent [i] = i;
        }

        void Union (int A, int B)
        {
            if (parent [A] == parent [B])
                return;
            else
            {
                int fA = FindParent (A);
                int fB = FindParent (B);

                if (sizes [fA] < sizes [fB])
                {
                    sizes [fB] += sizes [fA];
                    parent [fA] = fB;
                }
                else
                {
                    sizes [fA] += sizes [fB];
                    parent [fB] = fA;
                }
            }
        }

        int FindParent (int A)
        {
            if (parent [A] == A)
                return A;
            return parent [A] = FindParent(parent [A]);
        }
    };

    class SegmentTree
    {
        public:

        struct Node
        {
            Node *left, *right;
            int value;

            Node() { left = NULL; right = NULL;}
        };

        int values [1000], size;
        Node *root;

        SegmentTree() { }
        SegmentTree(int _size)
        {
            size = _size;
        }

        void InitTree(int code)
        {
            root = new Node();
            Initialize(code, root, 0, size - 1);
        }


        int Query (int code, int left, int right)
        {
            return query (code, root, 0, 6, left, right);
        }

        void Update (int index, int value)
        {

        }

        private:

        int query (int code, Node *node, int left, int right, int left_original, int right_original)
        {
            printf ("%d %d\n", left, right);
            if (right < left_original || right_original < left)
                return -1;
            if (left_original <= left && right <= right_original)
                return node->value;

            int p1 = query (code, node->left, left, (left + right) / 2, left_original, right_original);
            int p2 = query (code, node->right, (left + right) / 2 + 1, right, left_original, right_original);

            if (p1 == -1)
                return p2;
            else if (p2 == -1)
                return p1;

            if (code == RANGE_MIN)
                return min (p1, p2);
            else if (code == RANGE_MAX)
                return max (p1, p2);
        }

        int Initialize(int code, Node *node, int left, int right)
        {
            if (left == right)
            {
                node->value = values [left];
                return values [left];
            }

            node->left  = new Node();
            node->right = new Node();

            if (code == RANGE_MIN)
                node->value = min (Initialize (code, node->left,  left, (left + right) / 2),
                               Initialize (code, node->right, (left + right) / 2 + 1, right));
            else if (code == RANGE_MAX)
                node->value = max (Initialize (code, node->left,  left, (left + right) / 2),
                               Initialize (code, node->right, (left + right) / 2 + 1, right));

            return node->value;
        }
    };

    class BinaryIndexedTree
    {

    };

    class Graph
    {

    };
}

using namespace CompetitiveProgramming;

int n;
UnionFindStructure union_find;

int EnemyOf (int index)
{
    return index + 10001;
}

void setFriends(int u, int v)
{
    union_find.Union(u, v);
    union_find.Union(EnemyOf (u), EnemyOf (v));
}

void setEnemies(int u, int v)
{
    union_find.Union(u, EnemyOf (v));
    union_find.Union(EnemyOf(u), v);
}

int areFriends(int u, int v)
{
    //
    return (union_find.FindParent(u) == union_find.FindParent(v));
}

int areEnemies(int u, int v)
{
    //if u is a friend of an enemy of v, then they are enemies
    return (union_find.FindParent(u) == union_find.FindParent(EnemyOf (v)));
}

int main ()
{
    //freopen ("out.txt", "w", stdout);
    scanf ("%d", &n);

    union_find = UnionFindStructure(n + 10010);

    int x, y, c;
    while (true)
    {
        scanf ("%d %d %d", &c, &x, &y);

        if (c == 1)
        {
            if (areEnemies (x, y))
                printf ("-1\n");
            else
                setFriends (x, y);
        }
        else if (c == 2)
        {
            if (areFriends (x, y))
                printf ("-1\n");
            else
                setEnemies (x, y);
        }
        else if (c == 3)
        {
            printf ("%d\n", areFriends(x, y));
        }
        else if (c == 4)
        {
            printf ("%d\n", areEnemies(x, y));
        }
        else
            break;

    }

    return 0;
}












