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
    vector<int> rightSideView(TreeNode* root) {
        // TC: O(n)
        // SC: O(n)

        queue<TreeNode*> q;
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        q.push(root);
        while (q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (i == qSize - 1) {
                    result.push_back(node->val);
                }

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return result;
    }
};