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
    TreeNode* backtracking(vector<int>& nums, vector<int>::iterator begin, vector<int>::iterator end){   //T(n) 
		
        if (end-begin< 1) return nullptr; 
        
        vector<int>::iterator it = max_element(begin, end); 			//O(n) 
        TreeNode* node = new TreeNode(*it); 
        
        node->left = backtracking(nums, begin, it); 					//T(n/2-1) 
        node->right = backtracking(nums, it+1, end); 					//T(n/2-1) 
        
        return node; 
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr; 
        //find the max 
        return backtracking(nums, nums.begin(), nums.end()); 
        
        
    }
};


// T(n) = O(n) + T(n/2-1)*2 
// T(n/2-1) = O(n/2-1) + T(n/4 -1/2 -1)*2 

// T(n) = O(n) + O(n/2)*2 + O(n/4)*2 + O(n/8)* 2 + .....
// T(n) = O(n) + 2*(1-(1/2)^n)) 
// k = n + 2*(1-(1/2)^n) 

