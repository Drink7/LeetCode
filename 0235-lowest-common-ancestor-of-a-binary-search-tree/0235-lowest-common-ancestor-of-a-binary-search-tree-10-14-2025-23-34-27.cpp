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
        // binary search tree -> tree is ordered
        // root > all nodes in left subtree
        // root < all nodes in right subtree
        // TC: (logn), n is tree size
        // TC: O(1)
        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }
        while (true) {
            int rootVal = root->val;
            int pVal = p->val;
            int qVal = q->val;

            if (rootVal > pVal && rootVal > qVal) {
                root = root->left;
            } else if (rootVal < pVal && rootVal < qVal) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr; // impossible
    }
};