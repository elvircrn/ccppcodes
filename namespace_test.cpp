#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

namespace cAlpha {

    template <class T>
    class BIT {

        vector <int> bit;
        int size;

        public: BIT () {
            puts ("Specify size of BIT template. -.-");
        }

        public: BIT (int size) {bit = vector <int> (size + 5);}

        public: void Set (T val, int ind) {
            while (ind <= size) {
                bit [ind] += val;
                ind += ind & (-ind);
            }
        }

        private: int Get (int ind) {

            int ret = 0;

            while (ind) {
                ret += bit [ind];
                ind -= ind & (-ind);
            }

            return ret;

        }

        public: int GetRange (int START, int END) {
            return Get (END) - Get (START - 1);
        }

    };

    template <class T>
    class BST {



    };

}

cAlpha::BIT <int> mojBit;

int main () {



    return 0;

}
