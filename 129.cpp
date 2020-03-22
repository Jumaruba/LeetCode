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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;   
        return aux(root, 0); 
        
    }
    
    int aux(TreeNode* node,int sum_ant){
        int aux1 = 0, aux2 = 0; 
        sum_ant += node->val; 
        if (node->left == NULL && node->right == NULL) return sum_ant; 
        if (node->left != NULL) aux1= aux(node->left, sum_ant*10); 
        if (node->right != NULL) aux2 = aux(node->right, sum_ant*10); 
        return aux1 + aux2; 
    }
};
