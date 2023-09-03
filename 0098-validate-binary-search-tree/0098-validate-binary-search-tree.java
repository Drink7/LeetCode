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
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        return checkValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private boolean checkValidBST(TreeNode root, long intervalMin, long intervalMax) {
        if (root == null) {
            return true;
        }

        if (root.val > intervalMin && root.val < intervalMax) {
            return checkValidBST(root.left, intervalMin, root.val) && checkValidBST(root.right, root.val, intervalMax);
        } else {
            return false;
        }
    }
}