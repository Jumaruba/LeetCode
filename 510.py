"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Optional[Node]':
        self.next = Node(float(inf))
        self.nodeVal = node.val
        self.visited = set([])
        self.traverseDown(node)
        
        if self.next.val == float(inf):
            return None
        return self.next  
        
    def traverseDown(self, node): 
        if node == None or node.val in self.visited:
            return 
    
        self.visited.add(node.val)
        if node.val > self.nodeVal and self.next.val > node.val:
            self.next = node
        
        
        self.traverseDown(node.left)
        self.traverseDown(node.right)
        self.traverseDown(node.parent)
        
        
        
