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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* actual = head; 
        ListNode* previous = head; 
        while(actual != nullptr){ 
            if(actual->val == val){
                if (actual == head) head = actual->next; 
                else previous->next = actual->next; 
                
            }
            else previous = actual; 
            actual = actual->next;            
        }
        return head; 
    }
};
