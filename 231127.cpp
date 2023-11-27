/*
leetcode 935번

체스말이 이동가능한건 8방향임. 근데 다이얼 상에서는 제약조건이 많으니까
그냥 정해두고 들어가면 좋을듯. 
글고 이거 개수가 많고 중복이 많아서 매번 다 세기에는 너무 많음. 
DP 활용해주면 좋을듯.
*/
class Solution {
public:

    
    // 1 -> 6, 8
    // 2 -> 7, 9
    // 3 -> 4, 8
    // 4 -> 0, 3, 9
    // 5 -> 없음
    // 6 -> 0, 1, 7
    // 7 -> 2, 6
    // 8 -> 1, 3
    // 9 -> 2, 4
    // 0 -> 4, 6
    vector<vector<int>> possible = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    bool isVisited[5001][10] = {false};
    int cache[5001][10] = {0};
    const int MOD = 1000000007;
    
    int visit(int position, int n)
    {
        if(n == 1) return 1;
        if(isVisited[n][position]) return cache[n][position];

        int &ret = cache[n][position];
        isVisited[n][position] = true;
        for(int & nextPosition: possible[position])
        {
            ret = (ret + visit(nextPosition, n - 1)) % MOD;
        }
        return ret;
    }

    int knightDialer(int n) {
        int ans = 0;
        for(int i = 0; i < 10; i++)
        {
            ans = (ans + visit(i, n)) % MOD;
        }
        return ans;
    }
};
