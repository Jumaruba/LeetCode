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
        

        
# Another similar code =======================================================================

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        less_than = float(inf)
        higher_than = float(-inf)
        
        return self.traverseTree(root, higher_than, less_than)
        
    def traverseTree(self, root, higher_than, less_than):
        if root == None:
            return True
        
        if root.val <= higher_than or root.val >= less_than:
            return False 
        
        
        isLeftAcceptable = self.traverseTree(root.left, higher_than, root.val)
        isRightAcceptable = self.traverseTree(root.right, root.val, less_than)
        
        return isLeftAcceptable and isRightAcceptable
        
        
