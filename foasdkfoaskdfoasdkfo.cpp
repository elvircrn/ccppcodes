class SegmentTree
{
public:
   vector <int> M;
   vector <int> values;
   int n, tree_length = -1;

   SegmentTree() { }
   SegmentTree(int N)
   {
       n = N;
       int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
       M.resize(length, 0);
       values.resize(N, 0);
       tree_length = length;
   }

   int Build (int code)
   {
       return build (code, 1, 0, n - 1);
   }

   int Query (int code, int b, int e)
   {
       return query (code, 1, 0, n - 1, b, e);
   }

protected:
   int build(int code, int node, int b, int e)
   {
       if (b == e)
       {
           if (code == RANGE_SUM)
               return M [node] = values [b];
           else
               M [node] = b;
       }
       else
       {
           int A = build(code, 2 * node, b, (b + e) / 2);
           int B = build(code, 2 * node + 1, (b + e) / 2 + 1, e);

           if (code == RANGE_MIN)
           {
               if (values [M [2 * node]] <= values [M[2 * node + 1]])
                   M [node] = M [2 * node];
               else
                   M [node] = M [2 * node + 1];
           }
           else if (code == RANGE_MAX)
           {
               if (values [M [2 * node]] >= values [M[2 * node + 1]])
                   M [node] = M [2 * node];
               else
                   M [node] = M [2 * node + 1];
           }
           else if (code == RANGE_SUM)
               return M [node] = A + B;
       }

       return 0;
   }

   int query(int code, int node, int b, int e, int i, int j)
   {
       if (i > e || j < b)
       {
           if (code == RANGE_SUM)
               return 0;
           else
               return -1;
       }

       if (b >= i && e <= j)
           return M[node];

       int p1 = query (code, 2 * node, b, (b + e) / 2, i, j);
       int p2 = query (code, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

       if (p1 == -1)
           return p2;
       else if (p2 == -1)
           return p1;

       if (code == RANGE_MIN)
           return min (p1, p2);
       else if (code == RANGE_MAX)
           return max (p1, p2);
       else if (code == RANGE_SUM)
           return p1 + p2;
   }

};
