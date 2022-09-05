#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
// (x,y)에서 k번째 글자부터 시작해서 단어를 만들수 있는지의 여부 
// -1: 아직 모름, 0 : 불가, 1: 가능
int cache[5][5][10] = {0};
char board[5][6] = {0};
char word[11] = {0};

int dp(int x, int y, int idx)
{
    // basecase 끝에 도달했거나 범위 벗어난 경우
    if(idx == strlen(word)) return 1;
    if(x < 0 || x >= 5 || y < 0 || y >= 5) return 0;

    int & ret = cache[x][y][idx];
    if(ret > -1) return ret;
    
    // 일단 첫글자 다르면 무조건 실패 
    if(board[x][y] != word[idx])
    {
        return ret = 0;
    }
    // 첫글자는 괜찮은 경우 -> 다음 글자들이 괜찮은지 살펴봐야함. 
    for(int i = 0; i < 8; i++)
    {
        if(dp(x + dx[i], y + dy[i], idx + 1))
        {
            return ret = 1;
        }
    }
    // 다음 글자들이 만족하지 않는 경우 -> 실패
    return ret = 0;
}

int main()
{
    int c, n;
    
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        for(int i = 0; i < 5; i++)
        {
            scanf("%s", board[i]);
        }
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", word);
            memset(cache, -1, sizeof(cache));
            bool isPossible = false;
            for(int x = 0; x < 5; x++)
            {
                for(int y = 0; y < 5; y++)
                {
                    if(dp(x, y, 0))
                    {
                        isPossible = true;
                        break;
                    }
                }
                if(isPossible) break;
            }
            string ans = isPossible ? "YES" : "NO";
            printf("%s %s\n", word, ans.c_str());
        }
    }
    return 0;
}