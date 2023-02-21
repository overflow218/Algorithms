#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char arr[20][1010];
vector<string> words(20);
vector<int> limit(20);
vector<int> idx(20, 0);

bool isSubstring(string x, string y)
{
    int limit = min(x.size(), y.size());
    for(int i = 0; i < limit; i++)
    {
        if(x[i] != y[i]) return false;
    }
    return true;
}

int main()
{
    int n, total = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
        string x = arr[i];
        limit[i] = x.size();
        words[i] = x;
        total += limit[i];
    }

    int cnt = 0;
    while(cnt < total)
    {
        char fast = 'Z' + 1;
        int tmpIdx = -1;
        string next;
        for(int i = 0; i < n; i++)
        {
            int check = idx[i];
            if(check == limit[i]) continue;
            if(arr[i][check] < fast)
            {
                fast = arr[i][check];
                tmpIdx = i;
                next = words[i].substr(check);
            }
            // 겹치는것에 대해서는 뒤에를 비교해야함..
            else if(arr[i][check] == fast)
            {
                string tmpNext = words[i].substr(check);
                // ab, abcd 처럼 하나가 다른하나의 접두사면 긴거를 선택해야함. 
                // 이유. 긴거 뒤에 나오는게 더 앞서는 알파벳이면 그게 이득임. 긴거 뒤에 나오는게 앞서는 알파벳이 아니더라도 그때가서 다시 고민하면 되기때문에 적어도 손해는 안봄
                if(isSubstring(next, tmpNext))
                {
                    if(next.size() < tmpNext.size())
                    {
                        next = tmpNext;
                        tmpIdx = i;
                    }
                }
                // subString아닐때는 사전순으로 앞서는놈 골라야함. 
                else if(tmpNext < next)
                {
                    next = tmpNext;
                    tmpIdx = i;
                }
            }
        }

        // 이런일은 없음. 디버깅용
        if(tmpIdx == -1)
        {
            throw(-1);
        }
        cout << fast;
        idx[tmpIdx]++;
        cnt++;
    }

    cout << '\n';
    return 0;
}