class Solution:
    def __init__(self):
        self.edge = {}
        self.cost = []
        self.hasApple = []

    def find(self, node: int):
        apple = self.hasApple[node]
        cnt = 0
        self.cost[node] = 0
        for sibling in self.edge[node]:
            if(self.cost[sibling] == -1):
                check = self.find(sibling)
                if(check):
                    apple = True
                    cnt += self.cost[sibling] + 2
        self.cost[node] = cnt
        return apple

    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        for i in range(n):
            self.edge[i] = []
        self.cost = [-1] * n
        self.hasApple = hasApple
        for a, b in edges:
            self.edge[a].append(b)
            self.edge[b].append(a)
        self.find(0)
        return self.cost[0]