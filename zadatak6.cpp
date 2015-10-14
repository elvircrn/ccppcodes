#include <iostream>
#include <string>

using namespace std;

int main()
{
    string FBI;
    getline(cin, FBI);
    int rez = 0;
    for(int i=0;i<FBI.length();i++)
    {
        if(FBI.substr(i,3) == "FBI")
            rez ++;
    }
    cout << rez << endl;
    return 0;
}
