#include<iostream>
#include<string>
#include<unordered_map>
#include <set>
using namespace std;

unordered_map<string, int> check;
set<string> s;
int main()
{
    int total = 0;

    string line;
    while(getline(cin, line))
    {
        total++;
        check[line]++;
    }

    for(auto elem: check)
    {
        s.insert(elem.first);
    }

    for(auto elem: s)
    {
        printf("%s %.4f\n", elem.c_str(), check[elem] * 100 / (double) total);
    }
    return 0;
}