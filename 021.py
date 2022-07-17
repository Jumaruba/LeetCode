# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        self.curr_s = list1
        self.curr_t = list2 
        if list1 == None and list2 == None: 
            return None 
        
        root = self.createRoot()
        self.curr_node = root 
        
        self.merge(root)
        
        return root 
    
    
    def createRoot(self): 
        if (self.curr_s == None) or (self.curr_t != None and self.curr_s.val > self.curr_t.val): 
            root = self.curr_t 
            self.curr_t = self.curr_t.next 
        else: 
            root = self.curr_s 
            self.curr_s = self.curr_s.next 
            
        return root 
    
    
    def merge(self, root): 
        while(self.curr_s != None or self.curr_t != None): 
            self.updateCurrNode() 

            
            
    # Updates the node and return the next node. 
    def updateCurrNode(self): 
        if (self.curr_s == None) or (self.curr_t != None and self.curr_s.val > self.curr_t.val): 
            self.curr_node.next = self.curr_t 
            self.curr_t = self.curr_t.next 
        else:
            self.curr_node.next = self.curr_s 
            self.curr_s = self.curr_s.next 
        self.curr_node = self.curr_node.next 
         
