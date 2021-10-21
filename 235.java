/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        if (sameSide(root, p, q)){
            root = p.val < root.val ? root.left : root.right; 
            return lowestCommonAncestor(root, p, q); 
        }
        else 
            return root; 
    }
    
    public boolean sameSide(TreeNode root, TreeNode node1, TreeNode node2){
        return (node1.val > root.val && node2.val > root.val) || (node1.val < root.val && node2.val < root.val); 
    }
    
    
    
}