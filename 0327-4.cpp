#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> in_edges(1001);
vector<vector<pair<int, int>>> out_edges(1001);
int ans = 987654321;
vector<int> isTrap(1001, -1);

bool isVisied[1001][1024] = {false};

struct State{
    int idx;
    int state;
    int cost;
    bool operator<(const State s2) const {
        return this->cost > s2.cost;
    }
};

priority_queue<State> pq;
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    for(const auto &road: roads)
    {
        // p -> q 비용이 s임. 
        int p = road[0], q = road[1], s = road[2];
        out_edges[p].push_back(make_pair(q, s));
        in_edges[q].push_back(make_pair(p, s));
    }

    for(int i = 0; i < traps.size(); i++)
    {
        isTrap[traps[i]] = i;
    }

    pq.push(State{start, 0, 0});
    int cnt = 0;
    while(!pq.empty())
    {
        State tmp = pq.top();
        pq.pop();
        int cost = tmp.cost, idx = tmp.idx, state = tmp.state;
        // 도착지에 도착한 경우 더 볼필요가 없다
        if(idx == end)
        {
            ans = min(ans, cost);
        }
        // 같은 상태의 현재 노드를 방문한 적이 있다면 더 볼 필요가 없다
        if(isVisied[idx][state]) continue;
        isVisied[idx][state] = true;
        
        // 함정인 경우 상태를 뒤집어준다
        if(isTrap[idx] > -1)
        {
            // 현재 켜져있는 경우 -> 꺼줘야함. 
            if(state & (1 << isTrap[idx]))
            {
                state = state & (~(1 << isTrap[idx]));
            } 
            // 꺼져있는 경우 켜줘야함.
            else 
            {
                state = state | (1 << isTrap[idx]);
            }
        } 

        for(int i = 0; i < in_edges[idx].size(); i++)
        {
            int from = in_edges[idx][i].first, dist = in_edges[idx][i].second;
            int flag = 0;
            if(isTrap[from] > -1)
            {
                // from 버튼도 눌려서 뒤집힌 경우
                if(state & (1 << isTrap[from])) flag++;
            }
            if(isTrap[idx] > -1)
            {
                // idx 버튼도 눌려서 뒤집힌 경우
                if(state & (1 << isTrap[idx])) flag++;
            }

            // 뒤집힌 횟수가 홀수번이면 이동할 수 있음.
            // 뒤집혀서 방문할 수 있는 경우
            if(flag % 2 == 1)
            {
                pq.push(State{from, state, cost + dist});
            }
        }

        for(int i = 0; i < out_edges[idx].size(); i++)
        {
            int to = out_edges[idx][i].first, dist = out_edges[idx][i].second;
            int flag = 0;
            // printf("to: %d, dist; %d\n", to, dist);
            if(isTrap[to] > -1)
            {
                // to 버튼도 눌려서 뒤집힌 경우
                if(state & (1 << isTrap[to])) flag++;
            }
            if(isTrap[idx] > -1)
            {
                // idx 버튼도 눌려서 뒤집힌 경우
                if(state & (1 << isTrap[idx])) flag++;
            }

            // 뒤집힌 횟수가 짝수번이면 이동할 수 있음.
            // 뒤집혀서 방문할 수 있는 경우
            if(flag % 2 == 0)
            {
                pq.push(State{to, state, cost + dist});
            }
        }
    }

    return ans;
}
