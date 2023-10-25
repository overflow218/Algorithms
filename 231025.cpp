/*
leetcode #779

이게 보면 알겠지만, 매번 갈때마다 2배씩 길이가 늘어남. 
n <= 30이라서 최대 21억개 넘개 발생하기때문에 직접 만드는건 거의 불가능에 가까움. 
일단 답은 0 아니면 1인데 이게 늘리고 늘려가면서 몇개가 나오는지를 판단하면 됨
일단 1단계부터 n단계까지 간다고 했을때 
0 1로 두개가 생기고 ... 타고타고 생기는건데, 앞쪽에 2 ^ (n-1)개, 뒤에 2^(n-1)개가 생김. 
이걸 k의 범위에 맞게 재귀적으로 쪼개고쪼개면 어렵지 않게 문제 해결가능함!
*/
class Solution {
public:
    // 2의 거듭제곱 담고있음.
    int square[31] = {0, 1};

    int find(int left_step, int value, int k)
    {
        if(left_step == 1) return value;
        if(k > square[left_step - 1]) return find(left_step - 1, (value + 1) % 2, k - square[left_step - 1]);
        return find(left_step - 1, value, k);
    }
    int kthGrammar(int n, int k) {
        for(int i = 2; i <= 30; i++)
        {
            square[i] = 2 * square[i - 1];
        }
        return find(n, 0, k);
    }
};
