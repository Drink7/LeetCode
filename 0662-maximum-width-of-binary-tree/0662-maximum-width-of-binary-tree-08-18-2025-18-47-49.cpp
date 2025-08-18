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
    int widthOfBinaryTree(TreeNode* root) {
        // bfs
        // traverse level
        // fake node val = -200
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode*, long long>> q; // root as 1
        long long width = 0;
        q.push({root, 1});

        while(q.size() > 0) {
            int qSize = q.size();
            long long left = 0;
            long long right = 0;
            for (int i = 0; i < qSize; i++) {
                auto [node, id] = q.front();
                q.pop();

                if (i == 0) {
                    left = id;
                }
                right = id;

                if (node->left) {
                    q.push({node->left, 2 * (id - left)});
                }

                if (node->right) {
                    q.push({node->right, 2 * (id - left) + 1});
                }
            }
            width = max(width, right - left + 1);
        }
        return width;
    }
};