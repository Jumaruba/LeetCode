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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans; 
        vector<int> level; 
        queue<TreeNode*> q; 
        TreeNode* nodeFim;
        TreeNode* nodeFim_prov; 
        
        if (root){
            q.push(root); 
            nodeFim = root; 
        }
        
        while(!q.empty()){
            
            TreeNode* t = q.front(); 
            q.pop();
            level.push_back(t->val); 
            
            if(t->left){
                q.push(t->left); 
                nodeFim_prov = t->left; 
            }
            if(t->right){
                q.push(t->right); 
                nodeFim_prov = t->right; 
            }   
            
            if (nodeFim == t){
                ans.push_back(level); 
                level.clear();
                nodeFim = nodeFim_prov;
            } 
            
        }
        
        return ans; 
    }
};
