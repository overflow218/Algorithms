# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 무조건 p <= q라고 상황 만들거임
        if(q.val < p.val):
            p, q = q, p
        if(q.val < root.val):
            return self.lowestCommonAncestor(root.left, p, q)
        if(root.val < p.val):
            return self.lowestCommonAncestor(root.right, p, q)
        return root
        