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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // direction by order
        // bfs + queue
        // level = even, <-
        // level = odd, ->
        // TC: O(n)
        // SC: O(n)
        queue<TreeNode*> q;
        bool isReversed = false;
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        q.push(root);
        while (q.size() > 0) {
            int qSize = q.size();
            vector<int> levelResult;
            for (int i = 0; i < qSize; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                levelResult.push_back(node->val);
            }
            if (isReversed) {
                reverse(levelResult.begin(), levelResult.end());
            }
            isReversed = !isReversed;
            result.push_back(levelResult);
        }
        return result;
    }
};