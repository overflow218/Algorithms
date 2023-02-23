#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char arr1[1001];
char arr2[1001];

// 각 수별 삭제해야하는 개수
int toDelete[10] = {0};
// 각 수별 남은 선택해야하는 수의 개수
int cnt[10] = {0};
vector<int> ans;
vector<vector<int>> idx(10);

// 선택한 애들
vector<vector<int>> chosen(10);

// x를 vec에 정렬순서 맞춰서 넣어줌.
void push(vector<int> & vec, int x)
{
    if(vec.empty() || vec.back() < x)
    {
        vec.push_back(x);
    } else 
    {
        for(int i = 0; i < vec.size(); i++)
        {
            if(x < vec[i])
            {
                vec.insert(vec.begin() + i, x);
                break;
            }
        }
    }
}

int main()
{
    scanf("%s %s", arr1, arr2);
    for(int i = 0; i < strlen(arr1); i++)
    {
        idx[arr1[i] - '0'].push_back(i);
    }

    for(int i = 0; i < strlen(arr2); i++)
    {
        toDelete[arr2[i] - '0']++;
    }

    for(int i = 0; i < 10; i++)
    {
        cnt[i] = idx[i].size() - toDelete[i];
    }

    for(int target = 9; target >= 0; target--)
    {
        while(cnt[target] > 0)
        {
            int tmpIdx = idx[target].back();
            idx[target].pop_back();
            push(chosen[target], tmpIdx);
            push(ans, tmpIdx);
            cnt[target]--;

            // target보다 큰 수들 중에서 target보다 뒤에 있는데 
            // 앞으로 옮겨주는게 이득인 녀석들은 옮겨줘야함.
            for(int i = 9; i > target; i--)
            {
                // 아예 선택할일이 없거나, 이미 target보다 앞에 있거나, 이미 다 사용해서 개선의 여지가 없는 경우 넘어가기
                if(chosen[i].empty() || chosen[i][0] < tmpIdx || idx[i].size() == 0) continue;
                int curIdx = chosen[i][0];
                int nextIdx = idx[i].back();
                // 앞으로 땡겨서 갱신을 할 수 있는 경우
                if(nextIdx < curIdx)
                {
                    // 근데 이미 있는 수들과 비교해서 떙겨도 괜찮은지 확인해야함.
                    // 더 큰 수들과의 관계가 바뀌지 않으면 괜춘
                    bool isOkay = true;
                    for(int j = 0; j < ans.size(); j++)
                    {
                        if(ans[j] < nextIdx) continue;
                        if(ans[j] > tmpIdx) break;
                        if(arr1[ans[j]] - '0' > i)
                        {
                            isOkay = false;
                            break;
                        }
                    }
                    if(isOkay)
                    {
                        // 기존에 있떤 자리를 없애줘야함.
                        // 이 연산으로 인해 순서가 바뀔일은 없을지 고민해보기
                        idx[i].push_back(chosen[i].front());
                        ans.erase(find(ans.begin(), ans.end(), chosen[i].front()));
                        chosen[i].erase(chosen[i].begin());

                        push(chosen[i], nextIdx);
                        push(ans, nextIdx);
                    }
                }
            }
        }
    }

    for(int i = 0; i < ans.size(); i++)
    {
        printf("%c", arr1[ans[i]]);
    }
    printf("\n");

    return 0;
}

/*
41315143
13
*/