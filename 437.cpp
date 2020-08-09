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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0; 
        int result = 0; 
        dfs(root, sum, result, sum); 
        return result; 
    }
    
    void dfs(TreeNode* root, int sum, int & result,int int_sum, bool first=true){

        result += sum - root->val == 0? 1: 0; 
 
        if (root->left != nullptr) {
            if (first) dfs(root->left, int_sum, result, int_sum); 
            dfs(root->left, sum - root->val, result, int_sum,false); 
        } 
        if (root->right != nullptr){
            if (first) dfs(root->right, int_sum ,result, int_sum); 
            dfs(root->right, sum - root->val, result, int_sum,false); 
        } 
         
        return;
        
    }
 };
