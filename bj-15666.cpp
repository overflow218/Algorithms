#include<iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

set<int> s;
vector<int> input;
int n, m;

void print_vec(vector<int> & chosen)
{
    for(int i = 0; i < m; i++)
    {
        printf("%d ", chosen[i]);
    }
    printf("\n");
}

void find(int idx, vector<int> & chosen){
    if(chosen.size() == m)
    {
        int tmp = 0;
        for(int i = 0; i < m; i++)
        {
            tmp += pow(10, i) * chosen[i];
        }
        if(s.find(tmp) == s.end())
        {
            s.insert(tmp);
            print_vec(chosen);
        }
        return;
    }
    
    for(int i = idx; i < n; i++)
    {
        chosen.push_back(input[i]);
        find(i, chosen);
        chosen.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int tmp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());
    vector<int> vec;
    find(0, vec);
    return 0;
}