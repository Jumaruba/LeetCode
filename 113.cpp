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
    vector<vector<int>> ans; 
    void helper(TreeNode* root, int sum, vector<int>& temp){
        
        if (root == nullptr) return; 
        temp.push_back(root->val);   
        sum = sum-root->val; 
        
        if (sum == 0 && root->left == nullptr && root->right == nullptr){
            ans.push_back(temp); 
            temp.pop_back(); 
            return ; 
        }  
        
        helper(root->left, sum, temp); 
        helper(root->right, sum, temp) ; 
        temp.pop_back(); 
   
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;  
        
        helper(root, sum, temp); 
        return ans; 
    }
};
