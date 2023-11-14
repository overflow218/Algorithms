/*
leetcode 1930번
일단 n이 10^5이라서 직접 3개 뽑는건 어려워보이네
길이가 3이라고 고정되어있으니 경우는 다음 2가지
1. 3개가 모두 같은글자 -> 각 글자가 3개 이상나온경우 1가지로 카운트. 중복안세는거 조심
2. XYX 와 같은 꼴. Y 인덱스가 x와 x 사이에 있는지만 체크해주기 

이거 어차피 중복은 안세니까 각 글자별로 맨 처음 위치, 맨 끝 위치를 세어주면 되겠다.
-> 이렇게 세면 X Y X Y X 이런경우일때 최소 최대만 비교하면 빠지는 경우가 몇가지 있음
*/

#include <algorithm>
class Solution {
public:
    vector<vector<int>> check = vector<vector<int>>(26);
    int countPalindromicSubsequence(string s) {
        int count[26] = {0};
        
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            count[idx]++;
            check[idx].push_back(i);
        }
        
        
        for(int i = 0; i < 26; i++)
        {
            if(count[i] >= 3) ans++;
            for(int j = 0; j < 26; j++)
            {
                if(i == j || count[i] == 0 || count[j] == 0) continue;
                auto it = lower_bound(check[j].begin(), check[j].end(), check[i][0]);
                if(it != check[j].end() && *it < check[i].back()) ans++;
            }
        }
        return ans;
    }
};
