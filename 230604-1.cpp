class Solution {
public:
    int root[100];
    int depth[100];

    int find(int x)
    {
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }

    void make(int x, int y)
    {
        x = find(x); 
        y = find(y);
        if(x == y) return;
        root[y] = x;
        depth[x] += depth[y];
    }

    bool isConnected(vector<vector<int>>& bombs, int i, int j)
    {
        long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
        long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
        long long d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        long long r = max(r1, r2);
        return d <= r * r; 
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            root[i] = i;
            depth[i] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(isConnected(bombs, i, j)) make(i, j);
            }
        }

        for(int i = 0; i < n; i++)
        {
            ans = max(ans, depth[i]);
        }
        return ans;
    }
};