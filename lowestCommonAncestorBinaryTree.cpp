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
    
    bool procura(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root) return false; 
        bool there_is_p = false; 
        bool there_is_q = false; 
        
        stack<TreeNode*> stk; 
        stk.push(root);
        while(!stk.empty()){
            TreeNode* t = stk.top(); 
            stk.pop(); 
            if (t == p) there_is_p = true; 
            if (t == q) there_is_q = true; 
            if (there_is_p && there_is_q) return true; 
            
            if (t->right) stk.push(t->right); 
            if (t->left) stk.push(t->left); 
        }
        
        return (there_is_p && there_is_q); 
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool t = procura(root, p, q);         //findout if there is p and q in the node
        TreeNode* m1= NULL;
        TreeNode* m2= NULL; 
        if (t){
            if (root->right) m1 = lowestCommonAncestor(root->right, p, q); 
            if (root->left)  m2 = lowestCommonAncestor(root->left, p, q);
            
            //m1 or m2 is NULL
            if (m1) return m1; 
            if (m2) return m2; 
            return root; 
        }
        return NULL;
    }
};

//BETTER SOLUTION 
//credits to: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/932/discuss/65225/stefanpochmann
/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
*/

