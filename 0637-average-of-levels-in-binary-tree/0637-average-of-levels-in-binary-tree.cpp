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
    vector<double> averageOfLevels(TreeNode* root) {
        // use long because roo val is -(2^31) ~ (2^31 - 1)
        // use BFS, queue
        // TC: O(n)
        // SC: O(n), queue max size
        vector<double> result;
        queue<TreeNode*> levelQ;
        levelQ.push(root);
        while (!levelQ.empty()) {
            int qSize = levelQ.size();
            long qSum = 0;
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = levelQ.front();
                levelQ.pop();
                qSum += node->val;
                if (node->left) {
                    levelQ.push(node->left);
                }

                if (node->right) {
                    levelQ.push(node->right);
                }
            }
            result.push_back((double)qSum / qSize);
        }
        return result;
    }
};