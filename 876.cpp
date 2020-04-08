/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getSize(ListNode* head){
        if (head->next == NULL) return 1; 
        int size = 0; 
        return getSize(head->next)+1; 
        
    }
    ListNode* middleNode(ListNode* head) {
        int middle = getSize(head)/2; 
        for (int i = 0; i < middle; i++){
            head = head->next; 
        }
        return head; 
    }
};
