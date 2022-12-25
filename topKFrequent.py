from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ho = Counter(nums).most_common()
        ans = []
        for i in range(k):
            ans.append(ho[i][0])
        return ans
        