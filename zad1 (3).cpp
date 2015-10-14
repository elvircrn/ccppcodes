#include <iostream>
int n;
std::pair <int, std::string> cities [10000];
int main()
{
    std::cin>>n;
    for (int i = 0; i < n; i++)
        std::cin>>cities [i].second>>cities [i].first;
    for (int i = 0; i < n; i++)
        cities [i].first *= -1;
    sort (cities, cities + n);
    for (int i = 0; i < n; i++)
        std::cout<<cities [i].second<<' '<<(-1) * cities [i].first<<std::endl;
    return 0;
}
