#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

long long a, b, c;
map<int, long long> check;

long long find(int n)
{
    if(check.find(n) != check.end())
    {
        return check[n];
    }
    if(n == 1)
    {
        return a % c;
    }
    long long tmp = n % 2 == 1 ? (find(n / 2 + 1) * find(n / 2)) % c : (find(n / 2) * find(n / 2)) % c;
    return check[n] = tmp;
}

int main()
{

    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld\n", find(b));
    return 0;
}