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
    public static int TBC = 0; // To Be Covered
    public static int COV = 1; // already COVered by others
    public static int CAM = 2; // placed a CAMera here
    
    private int count = 0;
    
    public int minCameraCover(TreeNode root) {
        count = 0;
        int rootResult = judge(root);
        if (rootResult == TBC) {
            count += 1;
        }
        return count;
    }
    
    public int judge(TreeNode node) {
        if (node == null) {
            return COV;
        }
        
        int lr= judge(node.left);
        int rr = judge(node.right);
        
        if (lr == TBC || rr == TBC) {
            count += 1;
            return CAM;
        }
        else if (lr == CAM || rr == CAM) {
            return COV;
        }
        else {
            return TBC;
        }
    }
}