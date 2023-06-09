class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        check = {}
        ans = []
        for word in strs:
            code = ''.join(sorted(word))
            if(code not in check):
                check[code] = []
            check[code].append(word)
        for key in check:
            ans.append(check[key])
        return ans