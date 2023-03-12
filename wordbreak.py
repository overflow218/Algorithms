class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        checker = {}
        # 0이면 불가능, 1이면 가능, -1이면 모름
        cache = [-1 for i in range(len(s) + 10)]
        for word in wordDict:
            if(word[0] not in checker):
                checker[word[0]] = []
            checker[word[0]].append(word)
        
        def check(idx: int):
            if(idx == len(s)):
                return True
            if(cache[idx] != -1):
                if(cache[idx] == 0):
                    return False
                return True
            
            if(s[idx] not in checker):
                cache[idx] = 0
                return False

            flag = 0
            for word in checker[s[idx]]:
                if(len(word) > len(s) - idx): continue
                if(s[idx: idx + len(word)] == word):
                    if(check(idx + len(word))):
                        flag = 1
            cache[idx] = flag
            return True if flag == 1 else 0
        
        return check(0)