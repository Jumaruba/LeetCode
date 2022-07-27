# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.traverse(root)
        return root
    
    def traverse(self, root): 
        if root == None: 
            return None
        
        lastLeft = self.traverse(root.left)
        lastRight = self.traverse(root.right)
        if root.left != None:
            prevRight = root.right      # Get the previous right. 
            root.right = root.left      # Say that the right is the left. 
            lastLeft.right = prevRight  # Connect the new right to the previous right
            root.left = None             
            
        # Return the last element to connect
        if root.right == None and root.left == None: 
            return root
        if lastRight == None:
            return lastLeft
        return lastRight
