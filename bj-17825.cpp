#include <iostream>
#include <vector>
using namespace std;

int NEXT[100] = {0};
int SPECIAL[100] = {0};
int ans = 0;

void check(int idx, int sum, vector<int> &horse, vector<int> &dice)
{
    if(idx == 10)
    {
        ans = max(ans, sum);
    } else 
    {
        for(int i = 0; i < 4; i++)
        {
            // 도착한 말은 패스
            int tmp = horse[i];
            int original = horse[i];
            if(tmp == -1) continue;
            
            for(int j = 0; j < dice[idx]; j++)
            {
                // 시작할때 특이점이면 바꿔줘야함.
                if(j == 0 && tmp % 10 == 0)
                {
                    tmp = SPECIAL[tmp];
                } else 
                {
                    tmp = NEXT[tmp];
                }
                if(tmp == -1) break;
            }
            
            // 도착한 경우
            if(tmp == -1)
            {
                horse[i] = tmp;
                check(idx + 1, sum, horse, dice);
                horse[i] = original;
            } 
            // 일반칸에서 끝난 경우
            else 
            {
                // 다른 말이 이미 존재하는 칸이 아닌지 확인해야함. 
                bool isPossible = true;
                for(int j = 0; j < 4; j++)
                {
                    if(i != j && horse[j] == tmp)
                    {
                        isPossible = false;
                        break;
                    }
                }

                if(isPossible)
                {
                    horse[i] = tmp;
                    int add = horse[i] > 40 ? horse[i] - 30 : horse[i];
                    check(idx + 1, sum + add, horse, dice);
                    horse[i] = original;
                }
            }
        }
    }

}

int main()
{
    vector<int> dice(10);
    vector<int> horse(4, 0);
    for(int i = 0; i < 10; i++)
    {
        cin >> dice[i];
    }

    for(int i = 0; i <= 40; i+= 2)
    {
        NEXT[i] = i + 2;
    }

    // 예외사항 처리
    SPECIAL[0] = 2;
    SPECIAL[10] = 13;
    SPECIAL[20] = 52;
    SPECIAL[30] = 58;
    SPECIAL[40] = -1;
    SPECIAL[60] = 35;

    // 10의 특이점
    NEXT[13] = 46;
    NEXT[46] = 19;
    NEXT[19] = 25;

    // 30의 특이점
    NEXT[58] = 27;
    NEXT[27] = 56;
    NEXT[56] = 25;

    // 20의 특이점
    NEXT[52] = 54;
    NEXT[54] = 25;

    // 공통 특이점
    NEXT[25] = 60;
    NEXT[60] = 35;
    NEXT[35] = 40;

    // 종료칸
    NEXT[40] = -1;

    check(0, 0, horse, dice);

    cout << ans << '\n';
    return 0;
}