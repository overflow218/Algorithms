# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = [root]
        ans = []
        while(q != []):
            tmpLevel = []
            cnt = len(q)
            for i in range(cnt):
                node = q[0]
                q.pop(0)
                if(node == None):
                    continue
                tmpLevel.append(node.val)
                q.append(node.left)
                q.append(node.right)
            if(tmpLevel == []):
                break
            ans.append(tmpLevel)
        return ans
                