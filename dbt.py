# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = 0
    def getHeight(self, root: Optional[TreeNode]) -> int:
        if(root is None):
            return -1
        h1, h2 = self.getHeight(root.left), self.getHeight(root.right)
        self.ans = max(self.ans, max(h1 + h2 + 2, max(h1, h2) + 1))
        return max(h1, h2) + 1
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.getHeight(root)
        return self.ans        