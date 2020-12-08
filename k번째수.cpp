#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  long long n, k;
  scanf("%lld %lld", &n, &k);
  long long start = 1;
  long long end = n * n;
  long long ans;
  while(start <= end)
  {
    long long mid = (start + end) / 2;
    long long cnt = 0;
    for(int i = 1; i <= n; i++)
    {
      cnt += min(mid / i, n);
      // mid/ i 가 n보다 클수도 있어서 이렇게 하는게 맞음. 
    }
    if(cnt < k) // 필요한 개수 보다 많으니깐 줄일 필요가 있다.
    {
      start = mid + 1;
    } else  // cnt >= k
    {
      ans = mid;
      end = mid - 1;
    }
    /*
    이게 cnt == k는 그냥 출력해버리고 
    cnt < k일때 end를 줄여버리는 생각을 하기 쉬운데 그러면 안됨. 
    왜냐면 mid = x일때 x가 여러개일수 있딴말이지 그래서 5, 6 ,7번째가 다 x인데 
    나는 6번째를 구하고있는데 cnt = 7이라고  그냥 end를 줄여버리면 절대로 x를 
    mid로 가질 수 없음. 그래서 같거나 작더라도 값만 기억해놓고 다시 루프를 돌아야 
    안전하게 답을 구할 수 있다. 
    요약 mid = x 일때 cnt 는 마지막 나오는 x의 번호임. 따라서 답이 x일수도 있으니깐 
    cnt > k라고 해서 x를 답이 아니라고 할 수 없다. 그니깐 조심해야돼. 
    */
  }

  printf("%lld\n", ans);
  return 0;
}

/*
도저히 고민하다가 모르겠어서 구글 검색해서 푼 문제. 
틀린문제는 나중에 다시 풀어본다. 
이렇게 기발하게 풀 수 있따니 정말 놀랍당. 
그리고 조심해야할 점. 
int x , y;
long long z = x * y;
이렇게 쓰면 우선 int로 계산을 마친다음에 long long 으로의 전환이 일어난다. 
즉, 오버플로우 일어나도 나는 아무것도 모른다는 말이지. 그니깐 이렇게 쓸거면
long long x, y, z;
이렇게 선언하고 써야 안전한다.


치욕스럽다 물론 고딩이 나보다 컴퓨터를 많이 하고 잘하겠지만,
대학생이 고딩보다 못하다니 치욕이다 치욕이야 
분발하자 최형진
*/
