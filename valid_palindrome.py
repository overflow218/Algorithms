class Solution:
    def isPalindrome(self, s: str) -> bool:
        parsed_s = ''.join([c for c in s if c.isalnum()]).lower()
        start = 0
        end = len(parsed_s) - 1
        while(start <= end):
            if(parsed_s[start] != parsed_s[end]):
                return False
            start += 1
            end -=1
        return True