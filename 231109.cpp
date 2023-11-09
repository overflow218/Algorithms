// leetcode 1759번
// 이거는 연속된 글자가 몇개인지가 중요함. 
// 연속된게 n개라면
/*
leetcode 1759번
이거는 연속된 글자가 몇개인지가 중요함. 
연속된게 n개라면 1개짜리 n개, 2개짜리 n -1개, 3개짜리 n-2개 ... 1까지
n(n + 1) / 2가 나오겠네

지금 예제는 
1, 2, 3, 2 니까
1 + 3 + 6 + 3 
-> 13 맞단말이지~
*/
class Solution {
public:

    long long calcul(long long n)
    {
        return n * (n + 1ll) / 2ll;
    }
    int countHomogenous(string s) {
        const long long MOD = 1000000007;
        long long ans = 0;
        char prev = s[0];
        int cont = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == prev) cont++;
            if(s[i] != prev)
            {
                prev = s[i];
                ans = (ans + calcul(cont)) % MOD;
                cont = 1;
            }
        }
        ans = (ans + calcul(cont)) % MOD;
        return ans;
    }
};
