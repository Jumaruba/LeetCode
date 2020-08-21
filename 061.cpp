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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == nullptr) return head; 
        ListNode * firstNode = head; 
        int counter = 1; 
        while(head->next != nullptr){
            counter ++; 
            head = head->next; 
        }
        int size = counter; 
        head->next = firstNode; 
        head = firstNode; 
        counter = 0; 
        while(head != nullptr){
            if (size - counter  -1 == k%size) 
            {   
                firstNode = head->next; 
                head->next = nullptr; 
                break; 
            }
            counter++; 
            head = head->next; 
            
        }
        return firstNode;  
    }
};
