class Solution:
    def addBinary(self, a: str, b: str) -> str:
        '''
        1. 문자열을 뒤집어서 배열에 담아준다음에 계산한다
        시간 O(n) 공간 O(n)
        2. 문자열째로 계산을 진행한다
        올림 값만 가지고 있으면서 하면 괜찮을듯. 
        '''
        if(a == '0'): return b
        if(b == '0'): return a
        c = [0 for i in range(max(len(a), len(b)) + 1)]
        for i in range(len(c) - 1):
            add = 0
            if(i < len(a)):
                add += ord(a[len(a) - 1 - i]) - ord('0')
            if(i < len(b)):
                add += ord(b[len(b) - 1 - i]) - ord('0')
            olim = add // 2
            c[i] += add
            if(c[i] > 1):
                c[i + 1] += c[i] // 2
                c[i] %= 2
        while(c and c[-1] == 0):
            c.pop()
        ans = ''
        for n in c:
            ans = str(n) + ans
        return ans