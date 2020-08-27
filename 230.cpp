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
    int kthSmallest(TreeNode* root, int& k) {
        int ret; 
        
         
        if (root->left) ret = kthSmallest(root->left, k);
        if (ret != 0) return ret; 
        k--;
        if (k == 0) return root->val;
        if (root->right) return kthSmallest(root->right, k);
        
        return 0; 
    }
    
};
