/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
    
    int max = INT_MIN; 
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0; 
        
        int actualMax = aux(root);
        return std::max(max,actualMax); 
    }
    int aux(TreeNode* root){
        if (!root) return 0;  
        int left = aux(root->left); 
        int right = aux(root->right); 
        max = std::max(max,right + left + root->val); 
        max = std::max(std::max(left, right) + root->val, max); 
        return std::max(std::max(left,right) + root->val, root->val); 
    }
    
    
     
    
};
