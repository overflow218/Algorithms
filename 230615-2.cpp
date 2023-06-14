class Solution:
    def intToRoman(self, num: int) -> str:
        lis = []
        ans = ''
        for idx, val in enumerate(str(num)):
            lis.append(int(val) * 10 ** (len(str(num)) - 1 - idx))
        print(lis)
        for val in lis:
            if(val >= 1000):
                ans += 'M' * (val // 1000)
            elif(val == 900):
                ans += 'CM'
            elif(val >= 500):
                ans += 'D' + 'C' * ((val - 500) // 100)
            elif(val == 400):
                ans += 'CD'
            elif(val >= 100):
                ans += 'C' * (val // 100)

            elif(val == 90):
                ans += 'XC'
            elif(val >= 50):
                ans += 'L' + 'X' * ((val - 50) // 10)
            elif(val == 40):
                ans += 'XL'
            elif(val >= 10):
                ans += 'X' * (val // 10)
            
            elif(val == 9):
                ans += 'IX'
            elif(val >= 5):
                ans += 'V' + 'I' * (val - 5)
            elif(val == 4):
                ans += 'IV'
            elif(val >= 1):
                ans += 'I' * val

        return ans