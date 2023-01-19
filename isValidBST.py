# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    check = []
    def find(self, root: Optional[TreeNode]):
        if(root):
            self.find(root.left)
            self.check.append(root.val)
            self.find(root.right)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.check = []
        self.find(root)
        for i in range(len(self.check) - 1):
            if(self.check[i] >= self.check[i + 1]):
                return False
        return True