class Solution:
    def oddString(self, words: List[str]) -> str:
        parsed = [list(ord(word[i+ 1]) - ord(word[i]) for i in range(len(word) - 1)) for word in words]

        idx = -1
        for i in range(len(parsed)):
            if(parsed[0] != parsed[i]):
                idx = i
                break
        if(parsed[0] != parsed[1] and parsed[1] == parsed[2]):
            return words[0]
        return words[idx]