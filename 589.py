"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
# Recursive 

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        self.preorder_list = []
        self.traverse_preorder(root)
        return self.preorder_list 
    
    def traverse_preorder(self, root):
        if root == None:
            return
        
        self.preorder_list.append(root.val)
        for node in root.children:
            self.traverse_preorder(node)
            
            
# ================================================ 

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        stack = [] 
        if root != None: 
            stack.append(root)
        preorder_list = []
        
        while stack:
            curr_node = stack.pop(-1)
            preorder_list.append(curr_node.val)
            
            num_child = len(curr_node.children)
            for node in range(num_child-1, -1, -1): 
                stack.append(curr_node.children[node]) 
                
        return preorder_list
            
