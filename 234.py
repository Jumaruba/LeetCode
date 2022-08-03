# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        self.firstHalf = [] 
        self.secondHalf = [] 
        
        numElements = self.countElements(head)
        self.getFirstHalf(head, numElements//2, 0)
        self.getSecondHalf(head, numElements//2, 0)
        
        firstHalfSize = len(self.firstHalf)
        secondHalfSize = len(self.secondHalf) 
        
        pf = 0 
        ps = secondHalfSize - 1
        while pf < firstHalfSize and ps >= 0: 
            if self.firstHalf[pf].val != self.secondHalf[ps].val:  
                return False 
            
            pf += 1 
            ps -= 1 
            
        return True 
            
        
    def countElements(self, head): 
        if head == None: 
            return 0 
        
        return 1 + self.countElements(head.next) 
    
    def getFirstHalf(self, head, half, counter): 
        if counter == half: 
            return 
        
        self.firstHalf.append(head)
        self.getFirstHalf(head.next, half, counter+1) 
        
    def getSecondHalf(self, head, half, counter): 
        if head == None: 
            return 
        
        if counter >= half: 
            self.secondHalf.append(head)
        self.getSecondHalf(head.next, half, counter+1)
        
