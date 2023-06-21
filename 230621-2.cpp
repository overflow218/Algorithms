class Solution {
public:
    void visit(int idx, vector<vector<int>>& isConnected, vector<bool> &isVisited)
    {
        if(isVisited[idx]) return;
        isVisited[idx] = true;
        for(int i = 0; i < isConnected.size(); i++)
        {
            if(isConnected[idx][i]) visit(i, isConnected, isVisited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size(), ans = 0;
       vector<bool> isVisited(n, false);
       for(int i = 0; i < n; i++)
       {
           if(!isVisited[i])
           {
                visit(i, isConnected, isVisited);
                ans++;
           }

       }
       return ans; 
    }
};