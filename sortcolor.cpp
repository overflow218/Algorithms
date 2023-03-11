class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = (int)nums.size() - 1, tmp;
        while(start < end)
        {
            if(nums[start] == 0)
            {
                start++;
            } else 
            {
                tmp = nums[start];
                nums[start] = nums[end];
                nums[end--] = tmp;
            }
        }
        if(nums[start] == 0) start++;
        end = (int)nums.size() - 1;
        while(start < end)
        {
            if(nums[start] == 1)
            {
                start++;
            } else 
            {
                tmp = nums[start];
                nums[start] = nums[end];
                nums[end--] = tmp;
            }
        }
    }
};

/*
1. 일단 2 pass로 풀수있는건 각각 개수 세고 다시 넣어주면 됨
2. 1 pass로 풀려면 맨앞에 0의 자리를 만들어주고 맨뒤에 2의 자리를 만들어주고
*/