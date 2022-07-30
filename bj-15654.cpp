#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> input;
bool isVisited[8] = {false};

void go(vector<int> & chosen)
{
    if(chosen.size() == m)
    {
        for(int i = 0; i < m; i++)
        {
            printf("%d ", input[chosen[i]]);
        }
        printf("\n");
    } else 
    {
        for(int i = 0; i < n; i++)
        {
            if(!isVisited[i])
            {
                chosen.push_back(i);
                isVisited[i] = true;
                go(chosen);
                chosen.pop_back();
                isVisited[i] = false;
            }
        }
    }
}

int main()
{
    int tmp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());
    
    vector<int> vec;
    go(vec);
    return 0;
}