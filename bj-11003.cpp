#include <iostream>
#include <queue>
using namespace std;

/*
i + 1 - l 과 i 
l이 무조건 1 이상이니까 절대 왼쪽값이 작을 경우는 없겠네.
그런 면에서 본다면 범위가 주어졌을때 [a, b] 사이에서 최솟값 
뽑아내는 연산을 최대 500만번을 해야한다는 말이네?
이게 또 생각해보면 계속 늘어나는게 아니고 길이가 l 짜리 블록이 
계속 한칸씩 옆으로 이동한다고 생각하면 됨.
1, 2, ... l 까지는 계속 넣어주고 그 이후로는 
하나씩 빼주면 되는거 아니겠음?
multiset 활용하면 될듯
근데 멀티셋쓰면 시간 초과난다
어차피 뒤에 들어오는 작은게 있으면 앞에 있는 애들은 다 의미 없는거니까
그냥 큐를 써야겠다
*/

int arr[5000001];
// (idx, val)
deque<int> q;

int main()
{
    int n, l;
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        while(!q.empty() && arr[q.back()] >= arr[i]) q.pop_back();
        q.push_back(i);
        
        if(q.front() == i - l) q.pop_front();
        printf("%d ", arr[q.front()]);
    }
    printf("\n");
    return 0;
}