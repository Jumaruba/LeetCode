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
    vector<vector<int>> V = {}; 
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return V; 
        vector<int> x; 
        aux(root, 0, x, sum); 
        return V; 
    }
    
    void aux(TreeNode* root, int actualSum, vector<int> v, int sum){
        v.push_back(root->val);         
        actualSum+= root->val; 
        if (root->left == NULL && root->right == NULL && actualSum == sum)
            V.push_back(v);    
        if (root->left != NULL) aux(root->left, actualSum, v, sum); 
        if (root->right != NULL) aux(root->right, actualSum, v, sum); 
        
    }
};
