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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr; 
        int mid = nums.size()/2; 
        TreeNode* head = new TreeNode(nums[mid]); 
        
        vector <int> left (nums.begin(), nums.begin()+mid); 
        vector<int>right(nums.begin()+mid+1, nums.end()); 
        head->right = sortedArrayToBST(right); 
        head->left = sortedArrayToBST(left); 
        
        return head; 
        
    }
    
};
//Even better to use iterators 

/*
class Solution {
public:
    using iter = vector<int>::const_iterator;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        
        return buildBST(nums.begin(), nums.end());
    }
    
    TreeNode* buildBST(iter b, iter e) {
        if (b >= e) return nullptr;
        
        iter m = b + (e - b) / 2;
        
        TreeNode* node = new TreeNode(*m);
        node->left = buildBST(b, m);
        node->right = buildBST(m + 1, e);
        
        return node;
    }
};
*/ 
