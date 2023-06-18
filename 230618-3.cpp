class Solution {
public:

    vector<int> same;
    vector<int> diff;
    int find(int x, vector<int>& arr)
    {
        if(x == arr[x]) return x;
        return arr[x] = find(arr[x], arr);
    }

    void make(int x, int y, vector<int>& arr)
    {
        x = find(x, arr); y = find(y, arr);
        if(x == y) return;
        arr[y] = x;
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; i++)
        {
            same.push_back(i);
            diff.push_back(i);
        }
        for(const auto& it: equations)
        {
            int x = it[0] - 'a';
            int y = it[3] - 'a';
            if(x == y && it[1] == '!') return false;
            if(it[1] == '=')
            {
                make(x, y, same);
            }
        }

        for(const auto& it: equations)
        {
            int x = it[0] - 'a';
            int y = it[3] - 'a';
            if(it[1] == '!')
            {
                // 같다고 선언된 경우
                if(find(x, same) == find(y, same)) return false;
            }
        }
        return true;
    }
};