from collections import deque

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead = set(deadends)
        visited = set()
        q = deque([target])
        visited.add(target)
        stage = 0
        while(q):
            loop = len(q)
            for _ in range(loop):        
                cur = q.popleft()
                if(cur in dead):
                    continue
                if(cur == '0000'):
                    return stage
                for i in range(4):
                    if(cur[i] == '0'):
                        new1 = cur[:i] + '1' + cur[i + 1:]
                        if(new1 not in visited):
                            q.append(new1)
                            visited.add(new1)
                        new2 = cur[:i] + '9' + cur[i + 1:]
                        if(new2 not in visited):
                            q.append(new2)
                            visited.add(new2)
                    elif(cur[i] == '9'):
                        new1 = cur[:i] + '0' + cur[i + 1:]
                        if(new1 not in visited):
                            q.append(new1)
                            visited.add(new1)
                        new2 = cur[:i] + '8' + cur[i + 1:]
                        if(new2 not in visited):
                            q.append(new2)
                            visited.add(new2)
                    else:
                        new1 = cur[:i] + chr(ord(cur[i]) + 1) + cur[i + 1:]
                        if(new1 not in visited):
                            q.append(new1)
                            visited.add(new1)
                        new2 = cur[:i] + chr(ord(cur[i]) - 1) + cur[i + 1:]
                        if(new2 not in visited):
                            q.append(new2)
                            visited.add(new2)
            stage += 1
        return -1