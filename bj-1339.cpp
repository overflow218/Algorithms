#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

/*
1. 큰 자리수에 나온 수일수록 큰 수를 가져야함
2. 자리수가 같을 경우에는 많이 나온 숫자가 더 큰 수를 가져야함.
*/

// 알파벳별로 뭐로 바꿀지 담고 있음
int convert[26] = {0};
// 알파벳별로 가장 큰 자리수 표시
int order[26] = {0};

vector<string> words;
int main()
{
    int n;
    scanf("%d", &n);
    char word[10];
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", word);
        int len = strlen(word);
        for(int j = 0; j < len; j++)
        {
            order[word[j] - 'A'] += (int)pow(10, len - j - 1);
        }
        string tmp = word;
        words.push_back(tmp);
    }

    for(int i = 0; i < 26; i++)
    {
        if(order[i] > 0)
        {
            pq.push(make_pair(order[i], i));
        }
    }

    int idx = 9;
    int ans = 0;
    while(!pq.empty())
    {
        ans += order[pq.top().second] * (idx--);
        pq.pop();
    }

    printf("%d\n", ans);
    return 0;
}

/*
87 * 9
988
*/