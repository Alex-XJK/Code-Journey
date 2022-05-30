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
    public TreeNode recoverFromPreorder(String traversal) {
        Stack<TreeNode> stack = new Stack<>();
        int total = traversal.length();
        for (int i = 0; i < total;) {
            // Check for level
            int level = 0;
            while (traversal.charAt(i) == '-') {
                level += 1;
                i++;
            }

            // Get current value
            int value = 0;
            while (i < total && traversal.charAt(i) != '-') {
                value *= 10;
                value += traversal.charAt(i) - '0';
                i++;
            }
            
            // Look for its parent node
            while (stack.size() > level) {
                stack.pop();
            }
            
            // Create new node
            TreeNode tn = new TreeNode(value);
            
            // Attache to existing node
            if (!stack.isEmpty()) {
                if (stack.peek().left == null) {
                    stack.peek().left = tn;
                }
                else {
                    stack.peek().right = tn;
                }
            }
            
            // Add this node to stack
            stack.add(tn);
        }
        
        // Remove all node except root
        while (stack.size() > 1) {
            stack.pop();
        }
        
        // Return result
        return stack.pop();
    }
}