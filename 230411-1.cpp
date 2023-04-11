#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

// (x, y) -> 번호 맵핑을 담고 있음. 
map<pair<int, int>, int> nodeToNum;
vector<vector<int>> tree = vector<vector<int>>(1001);

// connected[i][0] = i번 노드의 왼쪽자식, conneceted[i][1] = i번 노드의 오른쪽 자식
int connected[10001][2] = {0};

// 높이 변환을 위해 필요한 녀석들
set<int> heightBox;
unordered_map<int, int> heightConvert;

vector<int> preOrder;
vector<int> postOrder;
void findSibling(int x, int y, int leftLimit, int rightLimit)
{
    int current = nodeToNum[make_pair(x, y)];
    // 전위순회 기록
    preOrder.push_back(current);
    // 맨 밑의 자손이라 그냥 종료해주기!
    if(y == 0)
    {
        postOrder.push_back(current);
        return;
    }
    vector<int> & lowerTree = tree[y - 1];
    int idx = lower_bound(lowerTree.begin(), lowerTree.end(), x) - lowerTree.begin();
    int left = idx - 1, right = idx;

    // 왼쪽 자식 탐색
    if(left > -1 && left < lowerTree.size())
    {
        if(leftLimit < lowerTree[left])
        {
            int leftSibling = nodeToNum[make_pair(lowerTree[left], y - 1)];
            connected[current][0] = leftSibling;
            findSibling(lowerTree[left], y - 1, leftLimit, x);
        }
    }
    // 오른쪽 자식 탐색
    if(right > -1 && right < lowerTree.size())
    {
        if(lowerTree[right] < rightLimit)
        {
            int rightSibling = nodeToNum[make_pair(lowerTree[right], y - 1)];
            connected[current][1] = rightSibling;
            findSibling(lowerTree[right], y - 1, x, rightLimit);
        }
    }
    // 후위순회 기록
    postOrder.push_back(current);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int h = -1, rootIdx = -1;
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        heightBox.insert(nodeinfo[i][1]);
    }
    int cnt = 0;
    auto it = heightBox.begin();
    for(it = heightBox.begin(); it != heightBox.end(); it++)
    {
        heightConvert[*it] = cnt++;
    }
    
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0], y = nodeinfo[i][1];
        y = heightConvert[y];
        nodeinfo[i][1] = y;
        if(y > h)
        {
            h = y;
            rootIdx = i;
        }
        nodeToNum[make_pair(x, y)] = i + 1;
        tree[y].push_back(x);
    }
    for(int i = 0; i < cnt; i++)
    {
        sort(tree[i].begin(), tree[i].end());
    }
    
    findSibling(nodeinfo[rootIdx][0], nodeinfo[rootIdx][1], -1, 100001);
    return {preOrder, postOrder};
}