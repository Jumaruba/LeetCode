# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.preorderPos = 0
        self.preorderSize = len(preorder)
        self.preorder = preorder 
        node = self.solve(0, inorder) 
        return node
    
    
    def solve(self, level, arr):
        if len(arr) == 0 or self.preorderSize == self.preorderPos: 
            return None 
        
        
        elementVal = self.preorder[self.preorderPos]
        node = TreeNode(elementVal) 
        
        middleElementIndex = self.getMiddleIndex(arr, elementVal)
        self.preorderPos += 1
        node.left = self.solve(level+1, arr[:middleElementIndex])
        node.right = self.solve(level+1, arr[middleElementIndex+1:])
        
        return node 
        
    # TODO: to be improved 
    def getMiddleIndex(self, arr, middleElement):
        for index, element in enumerate(arr):
            if element == middleElement: 
                return index 
            
        # The element is not in the array
        return -1 
    
        
        
