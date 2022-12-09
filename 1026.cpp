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
    int maxAncestorDiff(TreeNode* root) {
        int best = 0;
        getMaxDiff(root, root->val, root->val, best); 
        return best; 

    }

    void getMaxDiff(TreeNode* root, int mx, int mn, int&best) { 
        if (root == NULL) return;
        best = max(best, max(abs(root->val-mx), abs(root->val- mn)));
        getMaxDiff(root->right, max(root->val, mx), min(root->val, mn), best); 
        getMaxDiff(root->left, max(root->val, mx), min(root->val, mn), best); 

    }
};
