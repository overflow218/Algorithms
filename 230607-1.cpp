class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        int check = a | b;
        for(int i = 0; i < 32; i++)
        {
            if((c & (1 << i)) == (check & (1 << i))) continue;
            if(c & (1 << i)) cnt++;
            if(!(c & (1 << i)) && (a & (1 << i))) cnt++;
            if(!(c & (1 << i)) && (b & (1 << i))) cnt++;
        }
        return cnt;
    }
};