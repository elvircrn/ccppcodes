#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool comp(double x, double y)
{
    return abs(x - y) < 0.000001f;
}

struct point
{
    double x, y;

    point() { }
    point(double _x, double _y) { x = _x; y = _y; }

    double dist()
    {
        double zero = 0;
        return distance(zero, zero, x, y);
    }

    void print()
    {
        cout<<x<<' '<<y<<endl;
    }
};

struct edge
{
    point a, b;
    double length;

    edge() { }
    edge(point _a, point _b) { a = _a; b = _b; length = distance(a.x, a.y, b.x, b.y); }

    bool scales_with(edge drugi)
    {
        #define prvi (*this)

        //stavi na istu tacku
        double offX = (drugi.a.x - prvi.a.x);
        double offY = (drugi.a.y - prvi.a.y);


        drugi.a.x += offX;
        drugi.a.y += offY;

        drugi.b.x += offX;
        drugi.b.y += offY;



        point V1 = point(prvi.b.x - prvi.a.x, prvi.b.y - prvi.a.y);
        point V2 = point(drugi.b.x - drugi.a.x, drugi.b.y - drugi.a.y);

        double d1 = V1.dist();

        V1.x /= d1;
        V1.y /= d1;

        double d2 = V2.dist();

        V2.x /= d2;
        V2.y /= d2;

        return (comp(V1.x, V2.x) && comp(V1.y, V2.y));

        #undef prvi
    }
};

class SimilarRatingGraph
{
public:

    vector <edge> edges;

    double maxLength(vector <int> date, vector <int> rating)
    {
        for (int i = 1; i < date.size(); i++)
        {
            edge help = edge();
            help.a = point((double)date [i - 1], rating [i - 1]);
            help.b = point(date [i], rating [i]);

            help.length = distance(help.a.x, help.a.y, help.b.x, help.b.y);

            edges.push_back(help);
        }

        double solution = 0;

        printf ("%d\n", edges [0].scales_with(edges [2]));

        for (int i = 0; i < edges.size(); i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {

                if (i == j)
                    continue;

                if (edges [i].scales_with(edges [j]))
                {
                    int one = i, two = j;
                    double len_one = 0, len_two = 0;
                    while (one < edges.size() && two < edges.size() && edges [one].scales_with(edges [two]))
                    {
                        len_one += edges [one].length;
                        len_two += edges [two].length;

                        one++;
                        two++;
                    }

                    solution = max (max (len_one, len_two), solution);
                }
            }
        }

        return solution;
    }
};

int main()
{
    //vector <int> date = {5,11,25,58,92,162,255,350,458,566,677,792,919,1051,1189,1331,1489,1673,1882,2093,2315,2541,2771,3012,3254,3524,3797,4087,4379,4675,4973,5278,5588,5904,6225,6550,6888,7249,7612,8018,8428,8847,9267,9688,10109,10530,10964,11407,11870,12340,12811,13288,13768,14249,14734,15242,15774,16306,16847,17400,17966,18533,19108,19692,20278,20871,21471,22074,22679,23297,23916,24553,25190,25829,26472,27135,27814,28497,29181,29865,30555,31272,31994,32729,33487,34246,35005,35764,36537,37326,38119,38913,39725,40538,41360,42185,43010,43840,44671,45509,46350,47205,48063,48932,49807,50691,51577,52464,53289,54119,54950,55788,56629,57484,58342,59211,60086,60970,61856,62743,63568,64398,65388};
    //vector <int> rating = {1505,1462,1436,1416,1463,1421,1411,1450,1497,1465,1423,1394,1391,1367,1358,1323,1310,1279,1268,1279,1311,1342,1359,1387,1414,1376,1424,1382,1373,1335,1359,1318,1275,1266,1227,1203,1168,1163,1184,1144,1169,1207,1250,1235,1209,1162,1124,1148,1168,1202,1190,1155,1179,1194,1195,1195,1203,1240,1218,1245,1220,1190,1208,1180,1182,1148,1139,1126,1152,1159,1147,1158,1112,1091,1101,1116,1123,1086,1126,1110,1128,1085,1132,1145,1135,1140,1117,1081,1120,1131,1081,1032,1071,1102,1071,1065,1068,1027,980,947,987,968,959,980,990,974,1003,996,999,958,911,878,918,899,890,911,921,905,934,927,930,889,844};
    //vector <int> date = {81,104,120,124,134,137};
    //vector <int> rating = {1866,2332,2510,2678,2876,3002};

    vector <int> date   = { 1, 2, 3, 4};
    vector <int> rating = { 4, 4, 4, 4 };

    SimilarRatingGraph asd;

    cout<<"solution: "<<asd.maxLength(date, rating)<<endl;


    return 0;
}





































