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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode *> q; 
        int count  = 0; 
        ListNode * node = head; 
        
        while(count < n){
            count ++; 
            q.push(node); 
            node = node->next; 
        }
         
        ListNode * previous = nullptr; 
        while (node != nullptr){
            previous = q.front(); 
            q.pop() ;
            q.push(node); 
            node = node->next; 
        }
        
        q.pop() ; 
        if (previous == nullptr) return q.empty()? nullptr: q.front(); 
        previous->next = q.empty() ? nullptr: q.front();
        
        return head; 
        
    }
};
