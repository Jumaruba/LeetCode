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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         
        ListNode * head = new ListNode(); 
        ListNode * actual = head;
        int sum; 
        int ovf = 0; 
        while( l1 != nullptr || l2 != nullptr){
            l2 = l2 == nullptr? new ListNode(): l2; 
            l1 = l1 == nullptr? new ListNode(): l1;
            
            sum = ovf + l1->val + l2->val; 
            actual->val = sum%10; 
            ovf =  sum/10;  
            l1 = l1->next; 
            l2 = l2->next; 
            
            if (l1 != nullptr || l2!= nullptr){
                actual->next = new ListNode(); 
                actual = actual->next; 
            }
            
        }
        while(ovf != 0){
            actual->next = new ListNode(ovf%10); 
            actual = actual->next; 
            ovf /= 10 ; 
        }
        
        return head; 
    }
};
