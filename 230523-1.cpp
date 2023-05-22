class Solution {
public:
    vector<int> counter = vector<int>(20001, 0);
    vector<int> ans;
    void find(vector<int> &vec, int k)
    {
        if(k == 0) return;
        vector<int> tmp;
        vector<int> ho;
        int pivot = counter[vec[0] + 10000];
        for(const int num: vec)
        {
            if(counter[num + 10000] < pivot) tmp.push_back(num);
            if(counter[num + 10000] >= pivot) ho.push_back(num);
        }
        if(tmp.size() > k) return find(tmp, k);
        if(tmp.size() <= k)
        {
            for(int i = 0; i < tmp.size(); i++)
            {
                ans.push_back(tmp[i]);
            }
            return find(ho, k - tmp.size());
        }

    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> vec;
        for(const int num: nums)
        {
            counter[num + 10000]++;
        }
        for(int i = 0; i <= 20000; i++)
        {
            if(counter[i] > 0)
            {
                vec.push_back(i - 10000);
            }
        }
        find(vec, k);
        return ans;
    }
};