// leetcode 191번
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n)
        {
            cnt += n % 2;
            n /= 2;
        }
        return cnt;
    }
};

/*
leetcode 135번
1 0 2 에 대해서
2 1 2 

1 2 2 
1 2 1
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1;
        // 앞에 놓은거 크기
        int prev = 1; 
        // 연속으로 작아지고 있는 개수
        int cont = 1;

        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i - 1] == ratings[i])
            {
                ans++;
                prev = 1;
                cont = 1;
            }
            if(ratings[i - 1] > ratings[i])
            {
                cont++;
                ans += cont;
                prev = cont - 1;
            }
            if(ratings[i - 1] < ratings[i])
            {
                ans += prev + 1;
                prev++;
                cont = 1;
            }
        }
        return ans;
    }
};
