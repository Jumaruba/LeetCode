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
class Compare{
    public: 
        
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val; 
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr; 
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq ; 
        for (ListNode* head: lists){
            while(head!= nullptr){
                pq.push(head); 
                head = head->next; 
            }
        }
        
        if (pq.empty()) return nullptr; 
        ListNode * head = pq.top();
        pq.pop(); 
        ListNode* now = head; 
        while(!pq.empty()){
            now->next = pq.top(); 
            pq.pop() ; 
            now = now->next; 
        }
        now->next = nullptr; 
        return head; 
    }
};


//------------------------------------------------------------------------------

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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr; 
        priority_queue<int,vector<int>, greater<int>> pq; 
        
        // O(n)*O(klogk)
        for (ListNode* ln: lists){
            while(ln != nullptr){
                pq.push(ln->val); 
                ln = ln->next; 
            }
        }
        if (pq.empty()) return nullptr; 
        ListNode * head = new ListNode(pq.top()); 
        pq.pop(); 
        ListNode * now = head; 
        
        while(!pq.empty()){
            now->next = new ListNode(pq.top()); 
            pq.pop(); 
            now = now->next; 
        }
        
        return head; 
        
        
    }
};
