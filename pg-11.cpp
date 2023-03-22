#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// i번 노드가 리프이면 참, 아니면 거짓
bool isLeaf[110] = {false};
// i번 노드가 현재 어느 자식을 가르키고 있는지 나타냄. 
int direction[110];
// 현재까지 i번 노드를 방문한 횟수
int Count[110] = {0};
// i번 노드의 target값을 만족시키기 위한 최소 횟수
int minCount[110] = {0};
// i번 노드의 target값을 만족시키기 위한 최대 횟수
int maxCount[110] = {0};
// i번 노드의 자식들을 담고 있음
vector<vector<int>> siblings(105);
// leaf 노드들의 인덱스를 담고 있음. 끝나는지 체크하기 위함
vector<int> leafIdx;

// 현재까지 숫자가 내려간 순서대로 담고 있음
vector<int> path;
bool isDone()
{
    for(const int& idx:leafIdx)
    {
        if(Count[idx] < minCount[idx]) return false;
    }
    return true;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    int nodeCount = target.size();
    for(int i = 0; i < edges.size(); i++)
    {
        siblings[edges[i][0]].push_back(edges[i][1]);
    }
    
    target.insert(target.begin(), 0);
    for(int i = 1; i <= nodeCount; i++)
    {
        if(siblings[i].empty()){
            isLeaf[i] = true;
            maxCount[i] = target[i];
            minCount[i] = (target[i] + 2) / 3;
            leafIdx.push_back(i);
            // printf("leaf: %d, min: %d, max: %d\n", i, minCount[i], maxCount[i]);
        } else {
            sort(siblings[i].begin(), siblings[i].end());
        }
    }
    
    while(!isDone())
    {
        // 공을 하나씩 떨어뜨려줄거임.
        int current = 1;

        while(!isLeaf[current])
        {
            int next = siblings[current][direction[current]];
            direction[current] = (direction[current] + 1) % siblings[current].size();       
            current = next;
        }
        
        Count[current]++;
        path.push_back(current);
        // 만약에 아직 다른 조건 다 만족못헀는데 최대 감당치보다 커지면 실패!
        if(Count[current] > maxCount[current])
        {
            return {-1};
        }
    }
    
    for(int i = 0; i < path.size(); i++)
    {
        int current = path[i];
        int check = 3 * (Count[current] - 1);
        Count[current]--;
        if(check >= target[current] - 1)
        {
            answer.push_back(1);
            target[current] -= 1;
        } else if(check >= target[current] - 2)
        {
            answer.push_back(2);
            target[current] -= 2;
        } else 
        {
            answer.push_back(3);
            target[current] -= 3;
        }
    }
    return answer;
}