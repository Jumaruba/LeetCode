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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack<TreeNode*> stk;
        if(root) stk.push(root);
        while(!stk.empty()) {
            TreeNode* t = stk.top();
            ans.push_back(t->val);
            stk.pop();
            if(t->right) stk.push(t->right);
            if(t->left) stk.push(t->left);
        }
        return ans;
    }
};
