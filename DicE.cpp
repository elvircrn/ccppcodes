#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int dp [100] [100], n;
struct matrix {
    int height, width, m [50] [50];
    matrix () {}
    matrix (int _h, int _w) {height = _h; width = _w; for (int i = 0; i < width; i++) for (int j = 0; j < height; j++) m [i] [j] = 0;}
