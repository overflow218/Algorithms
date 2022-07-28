#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int D(int n){
    return 2 * n < 10000 ? 2 * n : 2 * n % 10000;
}
int S(int n){
    return n > 1 ? n - 1 : 0;
}
int R(int n){
    return n / 10 + (n % 10) * 1000;
}
int L(int n){
    return n * 10 % 10000 + n / 1000;
}


queue<pari<int, >> q;


int main()
{
    int t, a, b;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);

    }

    
    tmp = (a, '')
    q = deque()
    q.append(tmp)
    while(len(q) > 0):
        current = q.popleft()
        if(current[0] == b):
            print(current[1])
            break
        else:
            q.append((D(current[0]), current[1] + 'D'))
            q.append((S(current[0]), current[1] + 'S'))
            q.append((L(current[0]), current[1] + 'L'))
            q.append((R(current[0]), current[1] + 'R'))

    return 0;
}