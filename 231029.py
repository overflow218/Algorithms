'''
leetcode 468번
'''
class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        def isIpv4() -> bool:
            parsed = queryIP.split('.')
            if(len(parsed) != 4): 
                return False
            for x in parsed:
                if(not x.isnumeric()):
                    return False
                if(int(x) > 255 or x != str(int(x))):
                    return False
            return True
        def isIpv6() -> bool:
            parsed = queryIP.split(':')
            if(len(parsed) != 8): 
                return False
            for x in parsed:
                if(len(x) > 4 or not x.isalnum()): 
                    return False
                # 그거 a-f아닌 알파벳도 잡아줘야함. 
                for c in x:
                    if(c.isalpha() and ord(c.upper()) > ord('F')):
                        return False
            return True
        if(isIpv4()): return "IPv4"
        if(isIpv6()): return "IPv6"
        return "Neither"


        
