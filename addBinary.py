class Solution:
    def addBinary(self, a: str, b: str) -> str:
        parsedA = [ord(i) - ord('0') for i in a]
        parsedB = [ord(i) - ord('0') for i in b]
        if(len(parsedA) > len(parsedB)):
            parsedA, parsedB = parsedB, parsedA
        for i in range(len(parsedA)):
            parsedB[-1 - i] += parsedA[-1 -i]
            if(len(parsedA) -2 - i >= 0):
                parsedB[-2 -i] += parsedB[-1 - i] // 2
                parsedB[-1 - i] %= 2

        for i in range(len(parsedB)):
            if(len(parsedB) -2 - i >= 0):
                parsedB[-2 -i] += parsedB[-1 - i] // 2
                parsedB[-1 - i] %= 2
        if(parsedB[0] > 1):
            parsedB[0] %= 2
            return '1' + ''.join([chr(ord('0') + i) for i in parsedB])
        return ''.join([chr(ord('0') + i) for i in parsedB])