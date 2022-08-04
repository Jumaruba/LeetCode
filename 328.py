# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head 
        
        node = head 
        firstE = head.next 
        lastE = head.next 
        firstO = head
        lastO = head 
        
        while lastE != None and lastE.next != None: 
            lastO.next = lastE.next 
            lastO = lastO.next  # advance the lastO 
            prevLastONext = lastO.next 
            lastO.next = firstE 
            lastE.next = prevLastONext 
            lastE = lastE.next
            
            
        
        return firstO
