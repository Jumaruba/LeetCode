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
#define ull unsigned long long 
#define MOD 1000000007
class Solution {
public:
    int maxProduct(TreeNode* root) {
        ull totalSum = 0, best = 0;
        getTotalSum(root, totalSum);
        solve(root, best, totalSum);
        return best % MOD;
    }

    void getTotalSum(TreeNode* root, ull &totalSum){
        if (root == NULL) return ; 
        totalSum += root->val; 
        getTotalSum(root->left, totalSum);
        getTotalSum(root->right, totalSum);
    }
    
    ull solve(TreeNode* root, ull& best, ull& totalSum){
        if (root == NULL) return 0;
        ull right = solve(root->right, best, totalSum);
        ull left = solve(root->left, best, totalSum);
        best = max(left * (totalSum - left), best);
        best = max(right * (totalSum - right), best); 
        return root->val + left + right; 
    }
};
