# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Implemented with a small improvement

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.p = p
        self.q = q 
        
        if self.p.val < self.q.val:
            self.lowest = self.p
            self.highest = self.q 
        else:
            self.lowest = self.q 
            self.highest = self.p 
            
        self.ansNode = None 
        self.traverse(root)
        return self.ansNode 
        
    # acc = 1 => we have found the value of the node already. Don't any process. 
    # acc == -2 => the first node to receive this value is the common ancestor.  
    def traverse(self, root):
        acc = 0
        if root == None:
            return acc
        
        if root == self.p:
            acc = -1
        elif root == self.q:
            acc = -1
        
        acc_left = 0
        acc_right = 0
        if root.val > self.lowest.val:
            acc_left = self.traverse(root.left)
        if root.val < self.highest.val:
            acc_right = self.traverse(root.right) 
        
        if acc_left + acc_right + acc == -2:
            self.ansNode = root
            return 1 
    
        return acc + acc_left + acc_right
    
            
        
