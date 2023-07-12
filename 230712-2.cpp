class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        int idx = 0;
        while(idx < flowerbed.size())
        {
            if(flowerbed[idx] == 1)
            {
                idx++;
                continue;
            }
            int start = idx;
            while(idx < flowerbed.size() && flowerbed[idx] == 0) idx++;
            int end = idx - 1;
            int cnt = end - start + 1;
            if(start > 0) cnt--;
            if(end < (flowerbed.size() - 1)) cnt--;
            ans += (cnt + 1) / 2;
            idx = end + 1;
        }
        return ans >= n;
    }
};