# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getHeight(self, root: Optional[TreeNode]) -> int:
        if(root is None): return 0
        left_heigt, right_height = self.getHeight(root.left), self.getHeight(root.right)
        return max(left_heigt, right_height) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if(root is None): return True
        left_heigt, right_height = self.getHeight(root.left), self.getHeight(root.right)
        if(abs(left_heigt - right_height) > 1): return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)