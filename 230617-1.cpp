#include <algorithm>
#include <set>
#include <map>
#include <cstring>

class Solution {
public:
    // int cache[2001][2001];
    map<pair<int, int>, int> cache;
    bool isImpossible = false;
    // 이게 클때 바꾸는게 이득일지 아닐지를 모름. 그러니까 다 해보고 최솟값을 찾아야하네 쓔밤바
    // 가정. idx - 1 까지는 정렬이 되어있다고 생각함. 
    int find(int idx, int prev, vector<int>& arr1, vector<int>& arr2)
    {
        printf("idx: %d, prev: %d\n", idx, prev);
        if(idx == arr1.size()) return 0;
        auto it = cache.find(make_pair(idx, prev));
        if(it != cache.end()) return it -> second;
        int ret = 987654321;
        // 무조건 바꿔야함. 
        if(arr1[idx] <= prev)
        {
            int tmpIdx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
            if(tmpIdx < arr2.size())
            {
                ret = min(ret, 1 + find(idx + 1, arr2[tmpIdx], arr1, arr2));
            }
        }
        
        if(arr1[idx] > prev)
        {
            ret = min(ret, find(idx + 1, prev, arr1, arr2));
            int tmpIdx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
            if(tmpIdx < arr2.size() && arr2[tmpIdx] < arr1[idx])
            {
                ret = min(ret, 1 + find(idx + 1, arr2[tmpIdx], arr1, arr2));
            }
        }

        cache[make_pair(idx, prev)] = ret;
        return ret;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> s(arr2.begin(), arr2.end());
        vector<int> vec(s.begin(), s.end());
        int ans = find(0, -1, arr1, vec);
        for(int i = 0; i < arr1.size(); i++)
        {
            printf("arr1[%d]: %d\n", i, arr1[i]);
        }
        return ans > 3000 ? -1 : ans;
    }
};