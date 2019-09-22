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
    int findNumber(vector<int>& inorder, int number){
        for (int i = 0; i < inorder.size(); i++){
            if (inorder[i] == number) return i; 
        }
        return -1;
    }

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	if (preorder.empty() || inorder.empty()) return NULL; 

	int value = preorder[0]; 
	TreeNode* treeRoot = new TreeNode(value); 
	int position = findNumber(inorder, value); 
	preorder.erase(preorder.begin()); 

	vector<int> newInorder_left(inorder.begin(), inorder.begin()+position); 
	vector<int> newInorder_right(inorder.begin()+position+1, inorder.end()); 
	(treeRoot)->left = buildTree(preorder, newInorder_left);
	(treeRoot)->right = buildTree(preorder, newInorder_right); 
	return treeRoot; 
}
};
