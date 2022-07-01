# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_sum = -1001
        val = self.traverseTree(root, 0)
        self.max_sum = max(val, self.max_sum)
        return self.max_sum
    
    def traverseTree(self, root, curr_sum: int):
        if root == None:
            return -1001
        
        left_sum = self.traverseTree(root.left, curr_sum)
        right_sum = self.traverseTree(root.right, curr_sum)
        
        self.check_path(left_sum, right_sum, root.val)
        # Returning the path that contains the current node. 
        return root.val + max(max(left_sum, right_sum), 0)
    
    
    def check_path(self, left_sum, right_sum, node_val):
        self.max_sum = max(left_sum, self.max_sum)
        self.max_sum = max(right_sum, self.max_sum)
        self.max_sum = max(left_sum + right_sum + node_val, self.max_sum)

        
        
