#include <string>
#include <vector>
using namespace std;
    
// +, -, *, / 이 4개를 각각해서 나온는걸 찾아봐야겠넹... 
int cache[300000] = {0};
int checkList[] = {0, 1, 11, 111, 1111, 11111, 111111, 1111111};

int check(int x, int N)
{
    int ret = 0;
    for(int i = 0; i < 8; i++)
    {
        if(x == N * i){
            ret = i;
            break;
        }
    }
    return ret;
}

int find(int x, int N)
{
    if(x >= 300000 || x < 0) return 9;
    printf("%d 호출\n", x);
    int & ret = cache[x];
    if(ret) return ret;
    int tmp = check(x, N);
    if(tmp) return ret = tmp;
    ret = 1 + find(x - N, N);
    ret = min(ret, 1 + find(x + N, N));
    ret = min(ret, find(x - 1, N) + find(1, N));
    ret = min(ret, find(x + 1, N) + find(1, N));
    ret = min(ret, find(x * N, N) + 1);
    if(x % N == 0)
    {
        ret = min(ret, find(x / N, N) + 1);
    }
    return min(ret, 9);
}

int main()
{
    int N, number;
    scanf("%d %d", &N, &number);
    find(number, N);
    return 0;
}