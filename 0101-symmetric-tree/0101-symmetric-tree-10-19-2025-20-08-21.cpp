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
        // BFS + queue with nullptr value? -> OK
        // TC: O(n)
        // SC: O(n)
        /*
        if (root == nullptr) {
            return true;
        }
        return isHelper(root->left, root->right);
        */
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (q.size() > 0) {
            // tree usually pop two
            TreeNode* leftNode = q.front();
            q.pop();
            TreeNode* rightNode = q.front();
            q.pop();

            if (leftNode && rightNode && leftNode->val == rightNode->val) {
                q.push(leftNode->right);
                q.push(rightNode->left);
                q.push(leftNode->left);
                q.push(rightNode->right);
            } else {
                if (leftNode == nullptr && rightNode == nullptr) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool isHelper(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        } else {
            return isHelper(p->left, q->right) && isHelper(p->right, q->left);
        }
    }
};