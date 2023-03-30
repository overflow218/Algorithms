#include <string>
#include <vector>

using namespace std;

// 무조건 1을 y - x번 더하면 되니까 이거 벗어나면 불가능한거임
// cache[x] = 현재 x인데 타겟까지 가는데 필요한 최소횟수
vector<int> cache =  vector<int>(1000001, -2);
int target, diff;

int check(int current)
{
    if(current > target) return -1;
    if(current == target) return 0;
    int &ret = cache[current];
    if(ret != -2) return ret;
    
    ret = 987654321;
    if(check(current + diff) > -1) ret = min(ret, 1 + check(current + diff));
    if(check(current * 2) > -1) ret = min(ret, 1 + check(current * 2));
    if(check(current * 3) > -1) ret = min(ret, 1 + check(current * 3));
        
    return ret == 987654321 ? -1 : ret;
}
int solution(int x, int y, int n) {
    target = y; diff = n;
    if(x > y) return -1;
    return check(x);
}