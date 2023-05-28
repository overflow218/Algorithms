#include "stones.h"
#include <queue>
using namespace std;

int root[601];
int find(int x)
{
    if(x == root[x]) return x;
    return root[x] = find(root[x]);
}

void make(int x, int y)
{
    x = find(x);
    y = find(y);
    root[y] = x;
}

void stones(int N)
{
    std::vector<int> v1, v2;
    queue<int> big, small;

    for(int i = 1; i <= N; i++)
    {
        root[i] = i;
    }

    for(int i = 1; i <= N; i += 2)
    {
        if(i == N)
        {
            big.push(i);
            small.push(i);
            continue;
        }
        // compare(a, b) a가 크면 1, b가 크면 -1, 같으면 0
        int c = compare(i, i + 1);
        // 크기가 같은 경우에는 둘이 같은 팀이라고 표시해둔뒤 각각 big, small에 넣어줌
        if(c >= 0)
        {
            if(c == 0) make(i, i + 1);
            big.push(i);
            small.push(i + 1);
        }
        if(c == -1)
        {
            big.push(i + 1);
            small.push(i);
        }
        
    }

    while(big.size() > 1)
    {
        int cnt = big.size() / 2;
        for(int i = 0; i < cnt; i++)
        {
            int a = big.front(); big.pop();
            int b = big.front(); big.pop();
            int c = compare(a, b);
            // 크기가 같은 경우에는 둘이 같은 팀이라고 표시해둔뒤 각각 big, small에 넣어줌
            if(c >= 0)
            {
                if(c == 0) make(a, b);
                big.push(a);
            }
            if(c == -1)
            {
                big.push(b);
            }
        }

        for(int i = 0; i < cnt; i++)
        {
            int a = small.front(); small.pop();
            int b = small.front(); small.pop();
            int c = compare(a, b);
            // 크기가 같은 경우에는 둘이 같은 팀이라고 표시해둔뒤 각각 big, small에 넣어줌
            if(c >= 0)
            {
                if(c == 0) make(a, b);
                small.push(b);
            }
            if(c == -1)
            {
                small.push(a);
            }
        }
    }

    int MAX = big.front();
    int MIN = small.front();

    for(int i = 1; i <= N; i++)
    {
        if(find(i) == find(MIN)) v1.push_back(i);
        if(find(i) == find(MAX)) v2.push_back(i);
    }
    
    answer(v1, v2);
}