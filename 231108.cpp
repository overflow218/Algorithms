/*
leetcode 2849번
*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx);
        int y = abs(sy - fy);
        if(t < max(x, y)) return false;
        if(t == x + y + 1 && x == 0 && y == 0) return false;
        // 2칸 -> 왔다갔다로 가능. 3칸 -> 대각선 이동으로 가능. -> 4이상은 2, 3조합으로 가능
        // 1초 남았을때가 문제인건데... 이게 같은 자리인 경우랑 1번이라도 이동을 하는 경우가 다른것으로 보임. 
        // 1번이라도 이동이 필요한 경우 -> 1번에 이동할꺼를 2번으로 쪼개서 갈 수 있음. 
        // 시작점 == 끝점이라 이동이 필요 없는 경우 1번 이동후 되돌아올수가 없음. 그래서 안됨. 
        return true;
    }
};
