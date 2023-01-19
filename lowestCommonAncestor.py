# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if(p.val < root.val and root.val < q.val):
            return root
        elif(p.val > root.val and root.val > q.val): 
            return root
        elif(p.val < root.val and root.val > q.val and root.left):
            return self.lowestCommonAncestor(root.left, p, q)
        elif(p.val > root.val and root.val < q.val and root.right):
            return self.lowestCommonAncestor(root.right, p, q)
        return root