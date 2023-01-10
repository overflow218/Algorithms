from collections import Counter
class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        alphabet = 'abcdefghijklmnopqrstuvwxyz'
        counter1 = Counter(word1)
        counter2 = Counter(word2)
        
        cnt1 = len(counter1)
        cnt2 = len(counter2)
        for c1 in alphabet:
            if(c1 not in counter1):
                continue
            for c2 in alphabet:
                if(c2 not in counter2):
                    continue
                if(c1 == c2):
                    if(cnt1 == cnt2):
                        return True
                    continue
                new_cnt1 = cnt1
                new_cnt2 = cnt2
                if(c1 not in counter2):
                    new_cnt2 += 1
                if(counter1[c1] == 1):
                    new_cnt1 -= 1
                if(c2 not in counter1):
                    new_cnt1 += 1
                if(counter2[c2] == 1):
                    new_cnt2 -= 1
                if(new_cnt1 == new_cnt2):
                    return True
        return False