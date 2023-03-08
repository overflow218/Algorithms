"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def __init__(self):
        self.isVisited = {}
        
    def cloneGraph(self, node: 'Node') -> 'Node':
        if(node == None):
            return node
        # already copied node
        if(node.val in self.isVisited):
            return self.isVisited[node.val]
        
        # copy first time
        newNode = Node()
        newNode.val = node.val
        self.isVisited[newNode.val] = newNode
        
        for tmp_node in node.neighbors:
            newNode.neighbors.append(self.cloneGraph(tmp_node))
        
        return newNode
        