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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk; 
        vector<int> ans_2; 
        stack<int> ans; 
        
        if (root) stk.push(root); 
        
        while (!stk.empty()){
            TreeNode* t = stk.top(); 
            stk.pop(); 
            ans.push(t->val); 
            
            if(t->left) stk.push(t->left);
            if(t->right) stk.push(t->right); 
            
        }
        int size = ans.size(); 
        int value; 
        for (int i = 0; i < size; i++){
            value = ans.top(); 
            ans.pop(); 
            ans_2.push_back(value); 
        }
        return ans_2; 
    }
};
