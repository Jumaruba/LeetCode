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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) return head; 
        
        ListNode * ret_node = head; 
        ListNode * previous_first = nullptr; 
        ListNode * last = nullptr; 
        ListNode * previous = nullptr; 
        ListNode * next_= nullptr; 

        int counter = 0; 
        while(counter < n && head!= nullptr){
            counter ++;  
            previous_first = counter == m-1 ? head: previous_first; 
            last = counter == n? head: last; 
            next_ = head->next; 
            head->next = counter > m && counter <= n ? previous: head->next; 
            previous = head;
            head = next_;    
        }
        
        if (previous_first == nullptr) {
            ret_node->next = next_;  
        }
        else{
            previous_first->next->next = next_; 
            previous_first->next = last; 
            
        }
        return m == 1? last: ret_node;
    }
};
