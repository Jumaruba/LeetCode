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
public:
     
    
    bool result(TreeNode* root, int sum, int actual = 0){
        bool m = false, n = false; 
        
        actual += root->val; 
        if (!root->left && !root->right){
            if (actual == sum) return true; 
            return false; 
        }
        
        if (root->left) m = result(root->left,sum, actual); 
        if (root->right) n = result(root->right,sum, actual); 
        
        return (m||n); 
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root)
            return result(root, sum);
        return false; 
    }
};
