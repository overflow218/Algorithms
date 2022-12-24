class Solution:
    def toHex(self, num: int) -> str:
        dic = {10: 'a', 11: 'b', 12: 'c', 13: 'd', 14: 'e', 15: 'f'}
        if(num == 0):
            return '0'
        ans = ''
        if(num > 0):    
            while(num):
                tmp = num % 16
                ans = str(tmp) + ans if tmp < 10 else dic[tmp] + ans
                num //= 16
        else:
            lis = [ 15 & num >> (4 * (7 - i)) for i in range(8)]
            ans = ''.join([str(i) if i < 10 else dic[i] for i in lis])
        return ans
        