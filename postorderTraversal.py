# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = []

    def postoder(self, root: Optional[TreeNode]):
        if(not root):
            return
        self.postoder(root.left)
        self.postoder(root.right)
        self.ans.append(root.val)

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.postoder(root)
        return self.ans
        