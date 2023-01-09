"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
from collections import deque
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if(not root):
            return []
        ans = []
        q = deque([root])
        while(q):
            new_level = []
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                new_level.append(node.val)
                for child in node.children:
                    q.append(child)
            ans.append(new_level)
        return ans