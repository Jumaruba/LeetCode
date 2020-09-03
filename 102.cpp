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

//-----------------------------------------------------------------------


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
    
    vector<vector<int>> levelOrder(TreeNode* root) {   
        if (root == nullptr) return {}; 
        stack<TreeNode *> s;  
        stack<int> s_level; 

        vector<vector<int>> ans;  
        
        TreeNode* root_ = root;   
        int level = 0;   
        
        while(!s.empty() || root != nullptr) {
            
            while(root != nullptr){ 
                while(level + 1 > ans.size()) ans.push_back({});    
                ans[level].push_back({root->val});   

                s_level.push(level);
                s.push(root);  
                
                root = root->left;  
                level++; 
            }
            
            root = s.top();    
            s.pop();  
            //getting the level 
            level = s_level.top(); 
            s_level.pop() ;  
            
            root = root->right;  
            level ++; 
            
        }
        return ans; 
    }
};
