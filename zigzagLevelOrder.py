# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if(not root):
            return []
        ans = []
        q = deque([root])
        while(q):
            new_level = []
            limit = len(q)
            for _ in range(limit):
                node = q.popleft()
                if(not node):
                    continue
                new_level.append(node.val)
                q.append(node.right)
                q.append(node.left)
            if(len(new_level) > 0):
                if(len(ans) % 2 == 0):
                    ans.append(reversed(new_level))
                else:
                    ans.append(new_level)
        return ans