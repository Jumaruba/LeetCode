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
