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
    int appendLeft(stack<TreeNode*>& stk, TreeNode* root){
        while (root->left){
            stk.push(root->left); 
            root = root->left; 
        }
    }
    
   
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ; 
        stack<TreeNode*> stk;
        
        appendLeft(stk, )
        
        
    }
};