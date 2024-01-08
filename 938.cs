/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int RangeSumBST(TreeNode root, int low, int high) {
        Queue<TreeNode> q = new Queue<TreeNode>(); 
        q.Enqueue(root);
        int total = 0; 
        while (q.Count != 0){
            TreeNode node = q.Dequeue();
            if (node.val >= low && node.val <= high) 
                total += node.val;
            if (node.right != null) 
                q.Enqueue(node.right);
            if (node.left != null)
                q.Enqueue(node.left); 
        }
        return total; 
    }
}
