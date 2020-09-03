/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {}; 
        
        stack<TreeNode*> s_node; 
        stack<int> s_level; 
        int level = 0; 
        
        vector<vector<int>> ans; 
        
        while(root != nullptr || !s_node.empty()){
            
            
            while(root != nullptr){
                s_level.push(level); 
                s_node.push(root);    
                
                if (ans.size() < level+1) ans.push_back({}); 
                ans[level].push_back(root->val); 
                
                root = root->left; 
                level++; 
                
            } 
            
            root = s_node.top(); 
            level = s_level.top() ; 
            
            s_node.pop(); 
            s_level.pop(); 
            
            level ++; 
            root = root->right; 
        } 
        
        
        for (int i = 0 ; i < ans.size(); i++) {
            
            if (i%2 == 1) reverse(ans[i].begin(), ans[i].end()); 
        }
        
        return ans; 
        
    }
};
