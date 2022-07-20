# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        linkedListSize = self.getLinkedListSize(head, 0) 
        
        return self.getNode(head, 0, linkedListSize//2) 
        
    def getLinkedListSize(self, head, size): 
        if head == None:
            return size 
        return self.getLinkedListSize(head.next, size+1)
    
    def getNode(self, head, pos, target_pos):
        if head == None: 
            return -1 
        if pos == target_pos:
            return head 
        return self.getNode(head.next, pos+1, target_pos)
