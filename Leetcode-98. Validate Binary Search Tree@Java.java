/**
 * [LeetCode-WA] Wrong Answer.
 * Status: 68 / 80 test cases passed.
 * Use '<' and '>' rather than '<=' and '>=' to judge value,
 * which cannot satisfy the requirement of <b>less than</b> and <b>greater than</b>.
 * @example [2,2,2]
 * @see     https://leetcode.com/submissions/detail/848826972/
 */

/**
 * [LeetCode-WA] Wrong Answer.
 * Status: 72 / 80 test cases passed.
 * Use Integer.MIN_VALUE and Intger.MAX_VALUE to judge,
 * which cannot satisfy the requirement of {@code -2^31 <= Node.val <= 2^31 - 1}.
 * @example [2147483647]
 * @see     https://leetcode.com/submissions/detail/848827285/
 */

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
    
    public boolean isValid(TreeNode node, double min, double max) {
        if(node == null) {
            return true;
        }

        if(node.val <= min||node.val >= max) {
            return false;
        }

        boolean leftRes = isValid(node.left, min, node.val);
        boolean rightRes = isValid(node.right, node.val, max);

        if(leftRes && rightRes) {
            return true;
        }    
        else {
            return false;
        }
    }
    
    public boolean isValidBST(TreeNode root) {
        return isValid(root, Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY);
    }
}