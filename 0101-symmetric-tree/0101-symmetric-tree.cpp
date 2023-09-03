/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        /*
        // recursive
        // root == nullptr, Symmetric
        // traverse left, right tree
        // TC: O(n)
        // SC: O(1)
        if (root == nullptr) {
            return true;
        }
        return isSubSymmetric(root->left, root->right);
        */

        // Iterative
        if (root == nullptr) {
            return true;
        }
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                pair<TreeNode*, TreeNode*> p = q.front();
                q.pop();

                TreeNode* left = p.first;
                TreeNode* right = p.second;

                if (left && right) {
                    if (left->val == right->val) {
                        q.push({left->right, right->left});
                        q.push({left->left, right->right});
                    } else {
                        return false;
                    }
                } else {
                    if (left == nullptr && right == nullptr) {
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isSubSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }

        if (left != nullptr && right != nullptr) {
            if (left->val == right->val) {
                return isSubSymmetric(left->right, right->left) && isSubSymmetric(left->left, right->right);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};