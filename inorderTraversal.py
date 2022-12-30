# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def __init__(self, val=0, left=None, right=None):
        self.ans = []

    def find(self, node: TreeNode):
        if(not node):
            return
        if(node.left):
            self.find(node.left)
        self.ans.append(node.val)
        if(node.right):
            self.find(node.right)
            
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.find(root)
        return self.ans