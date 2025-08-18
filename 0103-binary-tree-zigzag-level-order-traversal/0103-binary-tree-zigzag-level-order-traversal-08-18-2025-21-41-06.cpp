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
        // bfs + deque
        // level = even, <-
        // level = odd, ->
        // TC: O(n)
        // SC: O(n)
        deque<TreeNode*> dq;
        bool isReversed = false;
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        dq.push_back(root);
        while (dq.size() > 0) {
            int dqSize = dq.size();
            vector<int> levelResult;
            for (int i = 0; i < dqSize; i++) {
                if (isReversed) {
                    auto node = dq.back();
                    dq.pop_back();
                    if (node->right) {
                        dq.push_front(node->right);
                    }
                    if (node->left) {
                        dq.push_front(node->left);
                    }
                    levelResult.push_back(node->val);
                } else {
                    auto node = dq.front();
                    dq.pop_front();
                    if (node->left) {
                        dq.push_back(node->left);
                    }

                    if (node->right) {
                        dq.push_back(node->right);
                    }
                    levelResult.push_back(node->val);
                }
            }
            isReversed = !isReversed;
            result.push_back(levelResult);
        }
        return result;
    }
};