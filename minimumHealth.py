class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        ho = 0
        ans = 1
        for d in damage:
            ans += d
            ho = max(ho, d)
        return ans - min(ho, armor)