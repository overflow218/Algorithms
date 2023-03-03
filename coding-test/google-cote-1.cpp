#include <iostream>
using namespace std;

/*
구글 코테 첫번째 문제 복기
문제 내용 
문자열 S가 주어짐. S의 길이는 최대 10만.
문자열의 각 문자는 'A', 'C', '?' 3 개 중에 하나임. 
현재 원형의 경로위에 있음.
A가 나오면 반시계 방향으로 1칸 움직임
C가 나오면 시계 방향으로 1칸 움직임
?가 나오면 어느쪽으로든 1칸 움직일 수 있음. 

이랬을때 최종적으로 원점에서 가장 멀리 떨어졌을때의 거리를 구하는게 문제. 
?를 어떻게 처리할지때문에 고생했음.
*/
int main()
{
    char S[100010];
    scanf("%s", S);
    int left = 0, right = 0, ans = 0;
    for(int i = 0; i < strlen(S); i++)
    {
        if(S[i] == 'A')
        {
            left--;
            right--;
        } else if(S[i] == 'C')
        {
            left++;
            right++;
        } else if(S[i] == '?')
        {
            left--;
            right++;
        }
        ans = max(ans, max(-left, right));
    }

    printf("%d\n", ans);
    return 0;
}