/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null){
            return null;
        }
        int rootValue = root.val;
        if(rootValue == val){
            return root;
        }
        else if(rootValue < val){
            return searchBST(root.right, val);
        }
        else if(rootValue > val){
            return searchBST(root.left, val);
        }
        else {
            return null;            
        }
    }
}