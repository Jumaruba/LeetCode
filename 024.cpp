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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head; 
        ListNode * dummy = new ListNode(0, head); 
        ListNode * f = dummy; 
        ListNode * s = head; 
        
        while(s != nullptr && s->next != nullptr){            // f = d && s = 1  => f->2->s->3 
            f->next = s->next;          // f->2->3   s->2
            s->next = f->next->next;    // f->2->3<-s    
            f->next->next = s;          // f->2->s->3
            
            f = s;      //d->2->f,s->3
            s = s->next;   
            
        }
        return dummy->next; 
    }
};
