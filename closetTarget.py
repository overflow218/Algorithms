class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        target_idxs = []
        for idx, word in enumerate(words):
            if(word == target):
                target_idxs.append(idx)
        if(not target_idxs):
            return -1
        ans = len(words)
        for target_idx in target_idxs:
            ans = min(ans, min(abs(target_idx - startIndex), len(words) - abs(target_idx - startIndex)))
        return ans