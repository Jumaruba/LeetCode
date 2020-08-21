/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* even = head->next; 
        ListNode* f_even = even; 
        ListNode * odd = head; 
        while(even != nullptr){
            if (even->next == nullptr) return head; 
            odd->next = even->next; 
            odd = odd->next; 
            even->next = odd->next; 
            odd->next = f_even; 
            even = even->next; 
      
        }
        
        return head; 
    }
};
