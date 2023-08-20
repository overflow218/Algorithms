#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int score[101] = {0};
int inTime[101] = {0};
vector<int> picture;

bool isIn(int val)
{
    for(const auto &it : picture)
    {
        if(it == val) return true;
    }
    return false;
}

void popMin()
{
    int idx = 0;
    for(int i = 1; i < picture.size(); i++)
    {
        if(score[picture[i]] < score[picture[idx]] || (score[picture[i]] == score[picture[idx]] && inTime[picture[i]] < inTime[picture[idx]]))
        {
            idx = i;
        }
    }

    score[picture[idx]] = 0;
    picture.erase(picture.begin() + idx);    
}

int main()
{
    int n, total, tmp;
    scanf("%d %d", &n, &total);

    for(int i = 0; i < total; i++)
    {
        scanf("%d", &tmp);
        if(!isIn(tmp))
        {
            if(picture.size() == n) popMin();
            picture.push_back(tmp);
            inTime[tmp] = i;
        }
        score[tmp]++;
    }

    sort(picture.begin(), picture.end());

    for (auto &it: picture)
    {
        printf("%d ", it);
    }
    printf("\n");
    return 0;
}