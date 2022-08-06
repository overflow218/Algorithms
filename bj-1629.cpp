#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

vector<long long> vec;
set<long long> s;

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long tmp = 1;
    for(long long i = 0; i < b; i++)
    {
        tmp *= a;
        tmp %= c;
        printf("%d번째 tmp: %lld\n", i + 1, tmp);
        if(s.find(tmp) == s.end())
        {
            s.insert(tmp);
            vec.push_back(tmp);
        } else 
        {
            break;
        }
    }
    for(int i = 0; i < vec.size(); i++)
    {
        printf("%lld ", vec[i]);
    }
    printf("\n");
    int idx = (b - 1) % (int)vec.size();
    printf("%lld\n", vec[idx]);
    return 0;
}