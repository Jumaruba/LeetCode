/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) { 
        int l1Val = 0, l2Val = 0, sum = 0; 
        ListNode l1Prev = null, l2Prev = null; 
        int upper = 0; 
        ListNode b1 = l1; 
        ListNode b2 = l2; 
        
        while(l1 != null && l2 != null){
            sum = (l1.val + l2.val + upper)%10;
            upper = (l1.val + l2.val + upper)/10; 
            
            l1.val = sum; 
            l2.val = sum; 
            
            l1Prev = l1; 
            l2Prev = l2; 
            
            l2 = l2.next; 
            l1 = l1.next; 
        }
        
        if (l1 != null) {
            this.getRemaining(l1, upper, l1Prev);
            return b1; 
        }
        else if (l2 != null) {
            this.getRemaining(l2, upper, l2Prev); 
            return b2; 
        } 
        if (upper != 0) l1Prev.next = new ListNode(upper); 
        return b1; 
    }
    
    public void getRemaining(ListNode l1, int upper, ListNode l1Prev){
        int sum = 0; 
        while (l1 != null) {
            sum = (l1.val + upper)%10; 
            upper = (l1.val + upper)/10; 
            
            l1.val = sum; 
            
            l1Prev = l1; 
            l1 = l1.next;
        } 
        if (upper != 0) l1Prev.next = new ListNode(upper); 
        
    }
}
