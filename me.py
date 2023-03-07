class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        '''
        1. 일단 정렬하고 한번 쭉 보면서 찾는다
        시간 O(nlogn) 공간 O(1)
        2. 카운터나 해시처럼 따로 세어준다
        시간 O(n), 공간 O(n)
        3. radix sort가 가능한가? 주어진 수의 범위가 너무 크다 
        4. 문제의 요구사항은 선형 시간안에 추가 공간없이 풀 수 있냐고 물어보고있다 
        일단 확실한건 무조건 majorityElement가 존재한다는점. 이아이는 과반이 넘는다는말이다
        1 2 1 2 1 2 1
        1 2 3 4 4 4 4 

        아 -10^9 부터 10^9까지 이분탐색하면 된다 
        근데 그거는 nlogn이 아닌게 n은 길이의 인자니까 범위의 인자는 아님..
        30 * nlogn이어도 괜춘한거임 ㅋㅋ
        '''
        start = -10**9
        end = 10**9
        ans = 0
        while(start <= end):
            mid = (start + end) // 2
            s, e = 0, 0
            for n in nums:
                if(n < mid):
                    s += 1
                else:
                    e += 1
            if(s < e):
                start = mid + 1
                ans = mid
            else:
                end = mid - 1
                ans = mid - 1
        return ans