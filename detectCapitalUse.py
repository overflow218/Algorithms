class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        ho = [1 if i.isupper() else 0 for i in word]
        all_sum = sum(ho)
        partial_sum = sum(ho[1:]) if len(word) > 1 else 0
        if(all_sum == 0 or all_sum == len(word) or (ho[0] == 1 and partial_sum == 0 )):
            return True
        return False