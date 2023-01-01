class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        check = {}
        parsed_words = s.split()
        if(len(pattern) != len(parsed_words)):
            return False
        for idx, word in enumerate(parsed_words):
            if(pattern[idx] not in check):
                if(word in check.values()):
                    return False
                check[pattern[idx]] = word
            else:
                if(check[pattern[idx]] != word):
                    return False
        return True