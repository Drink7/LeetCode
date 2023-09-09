/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        // check root->val (Recursive)
        // TC: O(logn)
        // SC: O(logn) -> recursion stack
        if (root == nullptr) {
            return root;
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
        */

        // check root->val (Iterative)
        // TC: O(logn)
        // SC: O(1) -> recursion stack
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else {
                break;
            }
        }
        return cur;
    }
};