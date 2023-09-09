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
        // make sure p->val < q->val
        // check root->val
        // TC: O(logn)
        // SC: O(logn) -> recursion stack
        if (root == nullptr) {
            return root;
        }

        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }

        if (p->val < root->val && q->val > root->val) {
            return root;
        } else if (p->val <= root->val && q->val > root->val) {
            return p;
        } else if (p->val < root->val && q->val >= root->val) {
            return q;
        } else {
            if (p->val > root->val) {
                return lowestCommonAncestor(root->right, p, q);
            } else {
                return lowestCommonAncestor(root->left, p, q);
            }
        }
    }
};