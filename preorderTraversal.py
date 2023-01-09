# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = []

    def preoder(self, root: Optional[TreeNode]):
        if(not root):
            return
        self.ans.append(root.val)
        self.preoder(root.left)
        self.preoder(root.right)

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.preoder(root)
        return self.ans
        