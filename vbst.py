# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def help(root: Optional[TreeNode], left:int, right:int) -> bool:
            if(root is None):
                return True
            if(root.left and (root.left.val >= root.val or root.left.val <= left)): return False
            if(root.right and (root.right.val <= root.val or root.right.val >= right)): return False
            return help(root.left, left, root.val) and help(root.right, root.val, right)
        return help(root, -2 ** 31 - 1, 2 ** 31)
        