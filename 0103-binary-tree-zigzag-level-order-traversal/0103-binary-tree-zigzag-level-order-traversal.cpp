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
        // traverse the root-> left, root-> right
        // reverse the order when even level
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;

        deque<TreeNode*> q;
        bool isReverse = false;
        q.push_back(root);
        while(!q.empty()) {
            int qSize = q.size();
            vector<int> levelList;
            for (int i = 0; i < qSize; i++) {
                TreeNode* node;
                if (isReverse) {
                    node = q.back();
                    q.pop_back();
                    if (node->right) {
                        q.push_front(node->right);
                    }

                    if (node->left) {
                        q.push_front(node->left);
                    }
                    
                } else {
                    node = q.front();
                    q.pop_front();
                    if (node->left) {
                        q.push_back(node->left);
                    }

                    if (node->right) {
                        q.push_back(node->right);
                    }
                }

                levelList.push_back(node->val);
            }
            isReverse = !isReverse;
            result.push_back(levelList);
        }
        return result;
    }
};