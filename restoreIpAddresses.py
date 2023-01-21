class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        def find(idx, tmp):
            if(idx == 4):
                if(sum(tmp) == len(s)):
                    cnt = 0
                    new_str = ''
                    for num in tmp:
                        tmp_s = s[cnt:cnt + num]
                        if(tmp_s[0] == '0' and len(tmp_s) > 1):
                            return
                        if(int(tmp_s) > 255):
                            return
                        new_str += tmp_s + '.'
                        cnt += num
                    ans.append(new_str[:-1])
                return 

            for i in range(1, 4):
                tmp.append(i)
                find(idx + 1, tmp)
                tmp.pop()

        find(0, [])
        return ans