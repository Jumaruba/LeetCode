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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        const int INF = 1e9 + 5; 
        if (l1 == nullptr && l2 == nullptr) return l1; 
        else if (l1 == nullptr) return l2; 
        else if (l2 == nullptr) return l1; 
        
        ListNode* head;
        ListNode* head_; 
        if (l1->val<= l2->val) {
            head = l1; 
            l1 = l1->next;   
        } 
        else{
            head = l2; 
            l2 = l2->next; 
        } 
        head_ = head; 
        while(l1!= nullptr && l2 != nullptr){
            if (l1->val <= l2->val){
                head->next = l1; 
                l1 = l1->next; 
            }
            else{
                head->next = l2;
                l2 = l2->next; 
            }
            head = head->next; 
        }
        if (l1 == nullptr) head->next = l2; 
        if (l2 == nullptr) head->next = l1; 
        return head_; 
    }
};
