#include <iostream>
#include <cstring>
using namespace std;

int cache[5010] = {0};
char arr[5010] = {0};
const int MOD = 1000000;

int find(int idx)
{   
    // 불가능한 경우 췤
    if(idx < strlen(arr))
    {
        // 맨처음에 0이거나 0다음에 0나오는 경우
        if(arr[idx] == '0')
        {
            return 0;
        }
    }

    if(idx + 1 >= strlen(arr))
    {
        return 1;   
    }
    int &ret = cache[idx];
    if(ret != -1) return ret;
    ret = find(idx + 1);
    if(arr[idx] == '1' || (arr[idx] == '2' && arr[idx + 1] <= '6'))
    {
        ret = (ret + find(idx + 2)) % MOD;
    }
    return ret;
}

int main()
{
    scanf("%s", arr);
    memset(cache, -1, sizeof(cache));
    cout << find(0) << '\n';
    return 0;
}

/*
11
110
2220
9876543210
*/