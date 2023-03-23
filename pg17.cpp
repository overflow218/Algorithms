#include <string>
#include <vector>

using namespace std;

int score = 0;
vector<int> ans;
void check(int idx, int arrow, vector<int> &info, vector<int> &chosen)
{
    // 화살을 다 쐈거나 더이상 쏠 과녁이 없는 경우 점수를 체크해줌. 
    if(idx < 0 || arrow == 0)
    {
        // 어차피 점수를 얻을수 있는 만큼은 다 쐈음. 그니까 남은 화살은 제일 점수 낮은거에다가 쏘는게 맞아
        chosen[10] += arrow;
        int apeach = 0, ryan = 0;

        for(int i = 0; i <= 10; i++)
        {
            if(info[i] >= chosen[i] && info[i] > 0)
            {
                apeach += 10 - i;
            } 
            if(info[i] < chosen[i] && chosen[i] > 0)
            {
                ryan += 10 - i;
            }
        }
        if(ryan - apeach > score)
        {
            score = ryan - apeach;
            ans.clear();
            ans = vector<int>(chosen.begin(), chosen.end());
        }
        chosen[10] -= arrow;
    } else 
    {
        // idx번 점수를 얻을건지 말건지를 선택해야함
        int needed = info[idx] + 1;
        // 얻고자 하면 점수 얻을 수 있는 경우
        if(needed <= arrow)
        {
            chosen[idx] = needed;
            check(idx - 1, arrow - needed, info, chosen);
            chosen[idx] = 0;
        }
        // idx번 점수 안얻고 넘어가는 경우
        check(idx - 1, arrow, info, chosen);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> chosen(11, 0);
    check(10, n, info, chosen);
    if(score == 0)
    {
        return {-1};
    } else 
    {
        return ans;
    }
}