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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// the final complexity is O(n)~? 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;  
        //what I can do is to parse it to an array 
        //O(n)
        while(head != nullptr){
            arr.push_back(head->val); 
            head = head->next; 
        }
        
        return aux(arr); 
        
    }
    
    TreeNode* aux(vector<int> nums){
        
        if (nums.empty()) return nullptr; 
        int mid = nums.size()/2; 
        TreeNode* head = new TreeNode(nums[mid]); 
        
        vector<int> left(nums.begin(), nums.begin()+mid); 
        vector<int> right(nums.begin()+mid+1, nums.end()); 
        head->left = aux(left); 
        head->right = aux(right); 
        return head; 
    }
};
