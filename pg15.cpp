#include <string>
#include <vector>
#include <queue>
using namespace std;

struct state{
    int current = 0;
    int sheep = 0;
    int wolf = 0;
    int isVisited = 0;
    int isKilled = 0;
};

// state가 담긴 큐
queue<state> q;
// i번 노드의 부모
int parent[17] = {0};

// 루트까지 가는데 만나는 늑대의 수를 리턴함.
pair<int, int> getCount(int x, vector<int> &info, int isKilled)
{
    int cnt = 0;
    while(x != 0)
    {
        int next = parent[x];
        // 다음칸이 늑대이고, 아직 안 죽은 경우
        if(info[next] == 1 && (isKilled & (1 << next)) == 0)
        {
            cnt++;
            isKilled |= (1 << next);
        }
        x = next;
    }
    return make_pair(cnt, isKilled);
}

bool isVisited(int flag, int idx)
{
    return flag & (1 << idx);
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int limit = 0;
    for(int i = 0; i < info.size(); i++)
    {
        if(info[i] == 0) limit++;
    }
    
    for(int i = 0; i < edges.size(); i++)
    {
        parent[edges[i][1]] = edges[i][0];
    }
    
    state check;
    q.push(state {0, 1, 0, 1, 0});
    
    while(!q.empty())
    {
        state current = q.front();
        q.pop();

        // printf("current : %d, sheep: %d, wolf: %d\n", current.current, current.sheep, current.wolf);
        if(current.sheep <= current.wolf) continue;
        // 안죽었을때만 의미가 있어요
        answer = max(answer, current.sheep);        
        for(int i = 1; i < info.size(); i++)
        {
            // 양이고 아직 안방문한 점에 대해서
            if(info[i] == 0 & !isVisited(current.isVisited, i))
            {
                pair<int, int> check = getCount(i, info, current.isKilled);
                int needed = check.first;
                // printf("%d에서 %d를 방문하러감\n", current.current, i);
                if(current.sheep - current.wolf > needed)
                {
                    q.push(state {i, current.sheep + 1, current.wolf + needed, current.isVisited | (1 << i), check.second});
                    
                }
            }
        }
        // break;
    }
    
    return answer;
}