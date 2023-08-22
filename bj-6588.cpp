#include <iostream>
#include <vector>
using namespace std;

bool isDeleted[1000001] = {false};
vector<int> primes;

//이거 대략 O(n) 시간에 컷
void init()
{
    for(int i = 3; i <= 1000000; i++)
    {
        if(isDeleted[i] || i % 2 == 0) continue;
        primes.push_back(i);
        for(int j = 2; i * j <= 1000000; j++)
        {
            isDeleted[i * j] = true;
        }
    }
}

void check(int n)
{
    for(auto &a: primes)
    {
        if(a >= n) break;
        if(!isDeleted[n - a])
        {
            printf("%d = %d + %d\n", n, a, n - a);
            break;
        }
    }
}
/*
일단 100만 이하의 홀수 소수가 대략 7만8천개정도임. 
a 에 대해서 n - a가 소수인지만 판단하면 되거든. 
어차피 이거 100만 이하는 무조건 성공임. 
글고 n에 대해서 무조건 n/2 이하로 대응하는 소수가 있으니까
하나도 대응 안된다고 해도 7만 * 10만 -> 70억의 연산인데
이런 워스트 케이스는 거의 없을듯?
*/


int main()
{
    int n;
    scanf("%d", &n);
    init();
    while(n != 0)
    {
        check(n);
        scanf("%d", &n);
    }
    return 0;
}