# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.calculate(nums, 0, len(nums))
    
    def calculate(self, nums, start, end):
        middle_pos = (end-start)//2+start

        if end < start or end < 0 or start == len(nums):
            return None 
        elif end == start:
            return TreeNode(nums[middle_pos])
        
        left_node = self.calculate(nums, start, middle_pos-1)
        right_node = self.calculate(nums, middle_pos+1, end)
            
        middle_node = TreeNode(nums[middle_pos], left_node, right_node)
        
        return middle_node
