# leetcode 1743번
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        is_done = set()
        mapping = {}
        for (a, b) in adjacentPairs:
            print(a, b)
            if(a not in mapping):
                mapping[a] = []
            if(b not in mapping):
                mapping[b] = []
            mapping[a].append(b)
            mapping[b].append(a)
        
        ans = []
        cur = 0
        for i in mapping:
            if(len(mapping[i]) == 1):
                cur = i
        ans.append(cur)
        is_done.add(cur)

        while(len(ans) <= len(adjacentPairs)):
            for adj in mapping[cur]:
                if(adj not in is_done):
                    ans.append(adj)
                    is_done.add(adj)
                    cur = adj
                    break
        return ans
