#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Shape {
    public: virtual void Draw () {cout<<"Shape."<<endl;}
};

class Circle : Shape {
    public: void Draw () {cout<<"Circle."<<endl;}
};

int main () {
    return 0;
}
