
namespace Competiton_ALPHA {

    template <class T>
    class BIT {

        vector <int> bit;
        int size;

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
    class Visited {

        class node {

            public:
            T val;
            node *leftNode, *rightNode;

            node () {}
            node (T a) {val = a; leftNode = rightNode = NULL;}

        };

        node *root;

        public: Visited () {root = NULL;}


    };

    template <class startPointer, class endPointer, class Function>
    void foreach (startPointer first, endPointer last, Function ff) {
        for (; first != last; first++) ff (*first);
    }

}
