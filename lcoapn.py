class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dic = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'};
        ans = []
        if(digits == ''):
            return []
        def make(chosen: str, digits: str):
            if(digits == ''):
                ans.append(chosen)
                return
            else:
                for c in dic[digits[0]]:
                    # print(f"c -> {c}")
                    make(chosen + c, digits[1:])
        
        make('', digits)
        return ans