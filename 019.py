# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        numberOfElements = self.countElements(head) 
        toRemovePos = numberOfElements - n # lenght = 1, n  = 1, 0 
        startNode = ListNode(-1, head)
        self.removeElement(startNode, None, toRemovePos, -1)
        
        return startNode.next 
        
    
    def removeElement(self, node: Optional[ListNode], prevNode, n, currPos): 
        if node == None: 
            return  
        
        if n == currPos: 
            prevNode.next = node.next
            return 
        
        self.removeElement(node.next, node, n, currPos+1)
        
        
    def countElements(self, node: Optional[ListNode]): 
        if node == None: 
            return 0 
        
        
        return self.countElements(node.next) + 1
