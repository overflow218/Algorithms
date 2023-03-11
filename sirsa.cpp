class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = (int)nums.size() - 1;

        if(nums.front() > target && nums.back() < target) return -1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(nums[start] == target) return start;
            if(nums[end] == target) return end;
            if(nums[mid] == target) return mid;
            
            // 다 같이 증가하는 일반적인 상황
            if(nums[start] < nums[end])
            {
                if(nums[mid] < target)
                {
                    start = mid + 1;
                } else if(nums[mid] > target) 
                {
                    end = mid  - 1;
                }
            } 
            // rotation때문에 뒤집힌 상황
            // else if(nums[start] > nums[end])
            else
            {
                if(nums[start] < nums[mid])
                {
                    if(nums[mid] < target)
                    {
                        start = mid + 1;
                    } else if(nums[mid] > target)
                    {
                        if(nums[start] > target)
                        {
                            start = mid + 1;
                        } else
                        {
                            end = mid - 1;
                        }
                    }
                } 
                // else if(nums[start] > nums[mid])
                else
                {
                    if(nums[mid] < target)
                    {
                        if(nums[end] > target)
                        {
                            start = mid + 1;
                        } else 
                        {
                            end = mid - 1;
                        }
                    } else if(nums[mid] > target)
                    {
                        end = mid - 1;
                    }
                }
            }
        }

        // 여기까지 왔으면 없는거임
        return -1;
    }
};

/*
1. 그냥 정렬만 되어있었다면 -> 이분 탐색으로 개꿀로 풀어낼 수 있음
2. 근데 지금 상황은 k만큼 회전을 하다보니 그냥 이분탐색으로는 찾기가 어려움... 
그렇게 되면 
증가하는 부분, 한번 감소하고 다시 증가하는 부분... 이렇게 나뉘게 된단 말이지~
부분1, 부분2
찾고자 하는 target이 부분1의 제일 앞보다 작다면 어떻게 해야할까?
-> 부분1에는 절대로 없을거고 부분2를 찾아봐야 맞는거임.
반대로 부분1의 제일 앞보다 크거나 같다면?
-> 부분2를 보는건 아무 의미가 없을거고 부분1을 보는게 맞는거임. 
이런 식으로 나눠서 탐색하도록 해주는게 좋을거 같은데
start, end, mid 가 있을때
a[start] < a[mid] < a[end] 이런 상황이라면 (애초에 맨첨에는 이렇게 안나옴)

아마 맨처음 재귀 돌때는
a[start] < a[mid] > a[end] 이거나
a[start] > a[mid] < a[end]
*/