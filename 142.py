# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        self.s = set([])
        return self.findStartCycle(head)
    
    def findStartCycle(self, head: Optional[ListNode]):
        if head == None:
            return None 
        if head in self.s:
            return head 
        self.s.add(head)
        return self.findStartCycle(head.next)
