#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i=0;i<n;i++)
    {
        cin >> x[i] >> y[i];
    }
    int result = n*3+4;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            if(x[i]==x[j] && y[i]+1==y[j])
                result --;
            else if(x[i]==x[j] && y[i]-1==y[j])
                result --;
            else if(x[i]+1==x[j] && y[i]==y[j])
                result --;
            else if(x[i]-1==x[j] && y[i]==y[j])
                result --;
        }
    }
    cout << result;
    return 0;
}
