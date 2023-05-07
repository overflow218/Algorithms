#include <string>
#include <vector>
#include <cstring>
using namespace std;

int arr[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
int cache[10][10][100001];
int getCost(int from, int to)
{
    int dx = abs(arr[from][0] - arr[to][0]);
    int dy = abs(arr[from][1] - arr[to][1]);
    if(dx == 0 && dy == 0) return 1;
    int diff = abs(dx - dy);
    return diff * 2 + min(dx, dy) * 3;
}

int find(int left, int right, int idx, string &numbers)
{
    if(idx == numbers.size()) return 0;
    int &ret = cache[left][right][idx];
    if(ret != -1) return ret;
    int next = numbers[idx] - '0';
    if(next == left || next == right) return ret = find(left, right, idx + 1, numbers) + 1;
    int cost1 = getCost(left, next);
    int cost2 = getCost(right, next);
    return ret = min(cost1 + find(next, right, idx + 1, numbers), cost2 + find(left, next, idx + 1, numbers));
}

int solution(string numbers) {
    memset(cache, -1, sizeof(cache));
    return find(4, 6, 0, numbers);
}