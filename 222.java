/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode righ) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int level = 0; 
    int total = 0; 
    public int countNodes(TreeNode root) {
        findLevel(root); 
        this.level--; 
        recursion(0, root); 
        
        return this.total; 
    }
    
    public void findLevel(TreeNode root){
        if (root == null) return; 
        
        this.total+= Math.pow(2, this.level); 
        this.level++; 
        
        findLevel(root.left); 
    }
    
    public boolean recursion(int currLevel, TreeNode root){
        if (root == null) return false; 
        
        if (currLevel == this.level-1){
            if (root.right != null) return true; 
            else this.total--; 
            
            if (root.left != null) return true; 
            else this.total--; 
        } else {
            
            if (recursion(currLevel+1, root.right)) return true; 
            if (recursion(currLevel+1, root.left)) return true;
        }
        
        return false; 
            
    }
} 

/*
 
An also interesting solution in python 

    def countNodes(self, root: Optional[TreeNode]) -> int:
        
        def left_height(root):
            if not root:
                return 0
            
            return 1 + left_height(root.left)
        
        def right_height(root):
            if not root:
                return 0
            
            return 1 + right_height(root.right)
        
        def count(root):
            if not root:
                return 0
            
            left = left_height(root)
            right = right_height(root)
            
            if left == right:
                return 2**left - 1
            else:
                return count(root.left) + count(root.right) + 1
            
        return count(root)

*/ 

/* Another simple solution in java with explanation here: 
https://jumaruba.github.io/_pages/others/CP/222-count-complete-tree-node.html


class Solution 
{
    public int countNodes(TreeNode root) 
    {
        if (root == null) return 0;

        TreeNode left = root, right = root;
        int l = 1, r = 1;
        
        while ((left  = left.left)   != null) ++l;
        while ((right = right.right) != null) ++r;
        
        if (l == r) return (1 << l) - 1;
        
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}
*/ 
