#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    int root[1000] = {0};
    
    int find(int idx)
    {
        if(idx == root[idx]) return idx;
        return root[idx] = find(root[idx]);
    }

    void make(int x, int y)
    {
        x = find(x);
        y = find(y);
        // x가 y의 부모
        root[y] = x;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<int, set<string>> checker;
        unordered_map<string, vector<int>> nameBook;
        vector<vector<string>> ans;

        for(int i = 0; i < accounts.size(); i++) root[i] = i;

        
        for(int i = 0; i < accounts.size(); i++)
        {
            string name = accounts[i][0];
            nameBook[name].push_back(i);

            // 일단 같은 이름인 사람중에 이메일 겹치는애 있는지 체크한다
            // 근데 여러명이랑 겹칠수도 있네. 그러면 이 여러명이 다같은 사람이 
            // 되어야하는거구만!
            vector<int> samePeople;
            for(int j = 0; j < (int)nameBook[name].size() - 1; j++)
            {
                int other = nameBook[name][j];
                for(int k = 1; k < accounts[i].size(); k++)
                {
                    if(checker[other].find(accounts[i][k]) != checker[other].end())
                    {
                        samePeople.push_back(other);
                        break;
                    }
                }
            }

            // 같은 사람이 있는경우 합쳐주기
            if(!samePeople.empty())
            {
                samePeople.push_back(i);
                for(int j = 1; j < samePeople.size(); j++)
                {
                    make(samePeople[0], samePeople[j]);
                }
            }  

            for(int j = 1; j < accounts[i].size(); j++)
            {
                checker[i].insert(accounts[i][j]);
            }
        }

        checker.clear();
        for(int i = 0; i < accounts.size(); i++)
        {
            int idx = find(i);
            for(int j = 1; j < accounts[i].size(); j++)
            {
                checker[idx].insert(accounts[i][j]);
            }
        }

        for(int i = 0; i < accounts.size(); i++)
        {
            if(find(i) != i) continue;
            vector<string> tmp;
            tmp.push_back(accounts[i][0]);

            auto it = checker[i].begin();
            while(it != checker[i].end())
            {
                tmp.push_back(*it);
                it++;
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};