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
    TreeNode * prev = new TreeNode(INT_MIN);  
    bool is = true; 
    bool prevAss = false; 
    bool isValidBST(TreeNode* root) {
        aux(root); 
        return is; 
    }
    void aux(TreeNode* root){
        if (!root) return; 
        aux(root->left); 
        if (root->val <= prev->val && prevAss){
            is = false;
            return; 
        }
        prev = root; 
        prevAss = true; 
        aux(root->right); 
    
    }
};
