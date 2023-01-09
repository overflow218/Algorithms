"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def __init__(self):
        self.ans = []
    
    def go(self, root: 'Node'):
        if(not root):
            return
        self.ans.append(root.val)
        for child in root.children:
            self.go(child)

    def preorder(self, root: 'Node') -> List[int]:
        self.go(root)
        return self.ans