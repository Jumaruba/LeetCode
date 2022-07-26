# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ancestor = 0 
        self.p = p 
        self.q = q
        self.traverse(root)
        return self.ancestor
        
        
    def traverse(self, root): 
        if root == None:
            return 0
        
        num_targets = 0
        if root == self.p or root== self.q:
            num_targets += 1
        
        num_targets += self.traverse(root.left)
        num_targets += self.traverse(root.right)
        
        if num_targets == 2:
            self.ancestor = root
            total = -1
            return -1
        
        return num_targets
