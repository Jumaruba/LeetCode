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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int totalSum = 0 ; 
        solve(root, low, high, totalSum);
        return totalSum; 
    }

    void solve(TreeNode* node, int& low, int& high, int& totalSum) { 
        if (node == NULL) return; 
        totalSum += node->val >= low && node->val <= high ? node->val: 0; 
        solve(node->left, low, high, totalSum);
        solve(node->right, low, high, totalSum); 

    }
};
