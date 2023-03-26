#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool isOdd(int x)
{
    return x % 2 == 1;
}

// a를 담고 있는 민힙
priority_queue<int> IN;
// b를 담고 있는 민힙
priority_queue<int> OUT;

// 형식적인 무한대를 의미
const int LIMIT = 2000000000;
// 현재 시작점부터의 누적된 파이프 개수를 의미함
int cnt = 0;
// 가장 최근의 시작점을 담고 있음
int last = -LIMIT;
// 왼쪽 괄호의 열림 닫힘을 표현함.
bool inclusive = false;

void process_IN()
{
    int in = -IN.top();
    IN.pop();
    int inCount = 1;
    while(!IN.empty() && -IN.top() == in)
    {
        IN.pop();
        inCount++;
    }

    // 홀수 -> 홀수. 이경우엔 뭐 바뀌는게 없음. last를 그대로 유지
    // 짝수 -> 짝수. 이 경우엔 구간을 합쳐줘야함. last를 그대로 유지함
    // 짝수 -> 홀수. 이 경우엔 구간을 출력해주어야함. last를 갱신해주기
    if(!isOdd(cnt) && isOdd(cnt + inCount))
    {
        // 지금 더해짐으로써 홀수개로 넘어간거니까 오른쪽은 ) 가 되는게 맞음.
        // last = 무한대인경우 예외처림
        if(last == -LIMIT)
        {
            printf("(-, %d)\n", in);
        }
        if(last != -LIMIT && inclusive)
        {
            printf("[%d, %d)\n", last, in);
        } 
        if(last != -LIMIT && !inclusive)
        {
            printf("(%d, %d)\n", last, in);
        }
        inclusive = false;
        last = in;
    }
    // 홀수 -> 짝수. in부터 새로운 구간이 생성되는거임. inclusive = true
    if(isOdd(cnt) && !isOdd(cnt + inCount))
    {
        last = in;
        inclusive = true;
    }
    // 모든 경우 공통적으로 cnt를 갱신해줘야함
    cnt += inCount;
}

void process_OUT()
{
    int out = -OUT.top();
    OUT.pop();
    int outCount = 1;
    while(!OUT.empty() && -OUT.top() == out)
    {
        OUT.pop();
        outCount++;
    }

    // 홀수 -> 홀수. 이경우엔 뭐 바뀌는게 없음. last를 그대로 유지
    // 짝수 -> 짝수. 이 경우엔 구간을 합쳐줘야함. 역시 last를 그대로 유지.
    // 짝수 -> 홀수. 이 경우엔 구간을 출력해주어야함. last를 갱신해주기
    if(!isOdd(cnt) && isOdd(cnt - outCount))
    {
        // 이경우에는 빼면서 짝수 -> 홀수로 넘어가는거니까 여기까지는 구간에 포함해줘야함. 오른쪽 괄호는 ]
        // 한점인 경우 예외 처리
        if(last == -LIMIT)
        {
            printf("(-, %d]\n", out);
            inclusive = false;
            last = out;
            cnt -= outCount;
            return;
        }
        if(last == out)
        {
            printf("<%d, %d>\n", last, last);
        }
        if(last != out && inclusive)
        {
            printf("[%d, %d]\n", last, out);
        }
        if(last != out && !inclusive) 
        {
            // 근데 이게 가능한 경우가 있나? 짝수가 되는 부분에서 무조건 inclusive = true일거 같은데
            printf("(%d, %d]\n", last, out);
        }
        inclusive = false;
        last = out;
    }
    // 홀수 -> 짝수. out부터 새로운 구간이 생성되는데 inclusive는 꺼줘야함.
    if(isOdd(cnt) && !isOdd(cnt - outCount))
    {
        last = out;
        inclusive = false;
    }
    // 모든 경우 공통적으로 cnt를 갱신해줘야함
    cnt -= outCount;
}

int main()
{
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        IN.push(-a);
        OUT.push(-b);
    }

    while(!IN.empty())
    {
        int in = -IN.top(), out = -OUT.top();
        // 새로운게 들어오는 상황
        if(in <= out)
        {
            process_IN();
        }
        if(out <= in)
        {
            process_OUT();
        }
    }

    while(!OUT.empty())
    {
        process_OUT();
    }

    // 맨 마지막 (, +) 이 출력이 남아있음   
    if(last == -LIMIT)
    {
        printf("(-, +)\n");
    }
    if(last != -LIMIT) 
    {
        if(inclusive) printf("[%d, +)\n", last);
        if(!inclusive) printf("(%d, +)\n", last);
    }
    return 0;
}
/*
3
1 3
2 4
5 6
-----
3
1 2
2 3 
3 4
-----
3
0 1
1 2 
1 2
----
4
0 1
1 2 
1 2
3 4
----
3
1 2
1 2
2 3
---- 
2 
1 2
1 2
----
3
1 3
1 3
2 4
----
2
1 2
1 3

반례 ---- 
2 
1 2 
1 3
--- 
2
1 3 
2 3
n = 2일때도 틀리니까 뭔가 로직에 문제가 있긴함
-> 역시 해결하고 보니 괄호 열고 닫는게 문제였음..
2
-1000000000 1000000000
1 2

안되는 반례 
2
1 2
1 3
*/