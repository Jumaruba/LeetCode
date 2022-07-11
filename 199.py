# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.result = []
        self.resultSize = 0 
        
        self.preOrder(root, 0) 
        
        return self.result 
        
        
    def preOrder(self, root: Optional[TreeNode], level):
        if root == None: 
            return 
        
        
        if self.resultSize <= level:
            self.result.append(root.val) 
            self.resultSize += 1
        else: 
            self.result[level] = root.val 
            
        self.preOrder(root.left, level + 1)
        self.preOrder(root.right, level + 1) 
        
        
