class Solution {
public:
    int counter[26] = {0};
    // 다시 접근가능한 시간을 나타냄
    int access[26] = {0};
    int leastInterval(vector<char>& tasks, int n) {
        for(int i = 0; i < tasks.size(); i++)
        {
            counter[tasks[i] - 'A']++;
        }

        int left = tasks.size();
        int ans = 0;
        while(left > 0)
        {
            int idx = -1, big = 0;
            for(int i = 0; i < 26; i++)
            {   
                if(access[i] <= ans && big < counter[i])
                {
                    big = counter[i];
                    idx = i;
                }
            }
            
            ans++;
            if(idx != -1)
            {
                counter[idx]--;
                access[idx] = ans + n;
                left--;
            }
        }
        return ans;
    }
};