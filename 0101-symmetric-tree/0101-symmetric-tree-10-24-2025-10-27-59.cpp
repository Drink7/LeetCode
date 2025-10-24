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
        // root must be symmetric
        // check left, right sub tree
        // iterative
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(q.size() > 0) {
            TreeNode* leftNode = q.front();
            q.pop();
            TreeNode* rightNode = q.front();
            q.pop();

            if (!leftNode && !rightNode) {
                continue;
            }

            if (!leftNode || !rightNode) {
                return false;
            }

            if (leftNode->val == rightNode->val) {
                q.push(leftNode->left);
                q.push(rightNode->right);
                q.push(leftNode->right);
                q.push(rightNode->left);
            } else {
                return false;
            }
        }
        return true;
    }

    bool helper(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p && q) {
            return p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left);
        } else {
            return false;
        }
    }
};