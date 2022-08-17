#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;

/*
문제해결 아이디어
- 일단 노드 개수가 최대 100000개이기 때문에 10^5 * 10^5 짜리 
배열을 만드는건 메모리상 불가능하다. 그래서 다른 방법을 찾아야한다. 
일단 트리라는 문제 조건에 맞게 모든 노드는 서로 도달가능하다. 
트리를 쭉 늘인다고 하면 
1 - 2- 3- 4- 5- ... 10 이런 꼴로 늘려줄 수 있다 
이렇게 했을때 각 정점에서 가장 멀리 떨어져있는 점을 구하고 
이때 값의 최대값이 주어진 트리의 지름이 되는 것이다!
근데 그림을 그려서 몇개 해보면 이렇게 늘인다는 게 내가 원하는 점을
루트로 만들 수 있다는 거고 거기서 쭉쭉쭉 타고 내려간다고 생각하면 됨. 
결국 루트를 1로 고정시키고 1에서 제일 멀리가는 점 구하면 됨. 
이때 1에서 2가고 2에서 1가고 ... 이런 무한루프를 막기위해서 
이미 구하러 들어간 점은 cache에 0으로 표시해두고 -1인 점만 탐색하도록 해주면 
이런 중복 문제를 해결할 수 있음
-> 근데 어떤 경우에는 한 노드의 자식 노드 두개까지의 거리를 더한게 최대 길이가 되는 경우도 있음. 
즉 내가 1번 노드를 임의로 루트로 정했지만 거기서 임의의 점 까지의 거리보다 더 큰 거리를 가지는 임의의 두쌍이 
존재할 수 있다는 거임. 이런 경우를 컨트롤하기 위해서 자식 노드가 2개이상 있을때는 값을 비교해주도록 함. 
-> 문제가 좀 치사했는데 문제를 잘 읽자. 정점 번호가 순.서.대.로 주어진다는 조건은 없다. 
이거 순서 뒤집혀서 들어온거때매 틀렸음 ㅡㅡ..
*/

map<int, vector<pair<int, int> > > tree;
int cache[100001];
int v, ans = 0;

int find(int node)
{
    int & ret = cache[node];
    if(ret != -1) return ret;
    ret = 0;
    vector<pair<int, int> > neighbor = tree[node];
    multiset<int> s;
    for(int i = 0; i < neighbor.size(); i++)
    {
        if(cache[neighbor[i].first] == -1)
        {
            s.insert(neighbor[i].second + find(neighbor[i].first));
        }
    }
    ret = s.size() > 0 ? *s.rbegin() : ret;
    int check = s.size() > 1 ? *s.rbegin() + *(++s.rbegin()) : 0;
    ans = max(ans, max(ret, check));
    // printf("node: %d, big: %d, small: %d, ret: %d\n", node, *s.begin(), *s.rbegin(), ret);
    return ret;
}

int main()
{
    scanf("%d", &v);
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < v; i++)
    {
        int from, to, dist;
        scanf("%d %d", &from, &to);
        vector<pair<int, int> > tmp_vec;
        while(to != -1)
        {
            scanf("%d", &dist);
            tmp_vec.push_back(make_pair(to, dist));
            scanf("%d", &to);
        }
        tree[from] = tmp_vec;
    }
    find(1);
    printf("%d\n", ans);
    return 0;
}

/*
순서 뒤집힌 예제
5

1 5 1 -1

5 1 1 4 10 -1

4 3 10 5 10 -1

3 2 10 4 10 -1

2 3 10 -1
*/