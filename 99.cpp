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
    TreeNode* first = NULL; 
    TreeNode* second = NULL; 
    TreeNode* prev = new TreeNode(INT_MIN); 
public:
    void recoverTree(TreeNode* root) {
        aux(root);            //find the two wrong nodes
        int value1 = first->val; 
        first->val = second->val; 
        second->val = value1; 
    }
    
    void aux(TreeNode* root){
        if (root == NULL) return; 
        aux(root->left); 
        if (first == NULL && root->val < prev->val) first = prev; 
        if (first != NULL && root->val < prev->val) second = root; 
        prev = root;    
        aux(root->right); 
         
    }
};
