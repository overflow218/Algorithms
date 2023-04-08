#include <string>
#include <vector>

using namespace std;

/*
이걸 진짜 터뜨리면서 모든 경우를 다 돌려보기에는
경우의 수가 너무 많음. 왜냐
1. 터뜨리는 순서 임의로 돌리는거만해도 n! 인데 n이 10^6임
2. 터트릴때마다 원소도 옮겨줘야하는데 이거도 매번 O(n)의 시간이 걸림
고로 문제에 주어진 조건의 의미를 파악해서 접근하는게 좋은 방법으로 보임
1번 빼고는 무조건 인접한거중에 큰 풍선이 터지는거임. 
그렇다면 제일 큰 풍선은 절대 남을일이 없겠네?
제일 작은 풍선은 1번의 예외가 아니라면 무조건 남을테고 
이런식으로 조금 생각해보면 제일 작은 풍선으로 나머지 풍선들을 다 터뜨리고
제일 작은 풍선만 특수조건 1번을 사용해서 해결할수 있는 상황인 풍선만
문제의 조건을 만족한다는것을 알 수 있음. 
*/

int solution(vector<int> a) {
    int n = a.size();
    int answer = 0;
    vector<int>leftMin(n);
    vector<int>rightMin(n);
    leftMin[0] = a[0];
    rightMin[n - 1] = a[n - 1];
    int tmp = 1000000001, minIdx = -1;
    for(int i = 1; i < n; i++)
    {
        leftMin[i] = min(leftMin[i - 1], a[i]);
        rightMin[n - 1 - i] = min(rightMin[n - i], a[n - 1 - i]);
        if(tmp > a[i])
        {
            tmp = a[i];
            minIdx = i;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        // 제일 작은건 무조건 가능
        if(i == minIdx) answer++;
        // 제일 작은 원소가 오른쪽에 있는 경우
        // 0~ i번째 원소중에서 i번째가 제일 작은 원소이면 가능
        if(i < minIdx && leftMin[i] == a[i]) answer++;
        
        // 제일 작은 원소가 왼쪽에 있는 경우
        // i ~ n - 1번째 원소중에서 i번째가 제일 작은 원소이면 가능
        if(i > minIdx && rightMin[i] == a[i]) answer++;
    }
    return answer;
}