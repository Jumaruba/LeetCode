# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = []
        
        
        
        def recursive(root, level):
            if root == None: 
                return 
            
            N = len(levels)
            if N <= level: 
                levels.append([])
                levels[level].append(root.val)
            else:
                levels[level].append(root.val)
                
            recursive(root.left, level+1)
            recursive(root.right, level+1)
            
        recursive(root, 0)
        return levels
        
