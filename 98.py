# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        ceil = float('inf')
        floor = float('-inf')
        return self.traverseTree(root.left,floor , root.val) and self.traverseTree(root.right, root.val, ceil) 
    
    
    def traverseTree(self, node, floor, ceil):
        if node == None: 
            return True 
        
        if node.val <= floor:
            return False 
        elif node.val >= ceil: 
            return False 
        
            
        isValidLeft = self.traverseTree(node.left, floor, min(ceil, node.val))
        isValidRight = self.traverseTree(node.right, max(floor, node.val), ceil)
        
        return isValidLeft and isValidRight
        
