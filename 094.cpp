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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk; 
        vector<int> ans; 
        if (root) stk.push(root);
        
        while(!stk.empty()){
            TreeNode* t = stk.top(); 
            stk.pop(); 
            
            /*reorganizing the stack*/ 
            if (t->right) stk.push(t->right); 
            stk.push(t); 
            if (t->left){ 
                stk.push(t->left);
                t->left = NULL;
                t->right = NULL;
            }
            else{
                ans.push_back(t->val); 
                stk.pop(); 
            } 
            
        
        }
        return ans; 
    }
};

/*
 recursive solution 
 class Solution {
private:
    vector<int> res;

public:
    vector<int> inorderTraversal(TreeNode* root) {

        if (root == NULL)
            return {};

        if (root->left != NULL)
            inorderTraversal(root->left);

        res.push_back(root->val);

        if (root->right != NULL)
            inorderTraversal(root->right);

        return res;
    }
};
*/
