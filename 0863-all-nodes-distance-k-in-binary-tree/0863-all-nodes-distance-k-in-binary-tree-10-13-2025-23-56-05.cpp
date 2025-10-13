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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // tree -> BFS
        // use queue / BFS with k steps to find distance k
        // what about the parent?
        // use hash map to store parent / child
        // TC: O(n)
        // SC: O(n)
        dfs(root);

        // start bfs k steps
        vector<int> result;
        queue<TreeNode*> q;
        q.push(target);
        while (q.size() > 0 && k >= 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (visited.count(node) > 0) {
                    continue;
                } else {
                    visited.insert(node);
                }

                if (k == 0) result.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }

                if (parentMap[node]) {
                    q.push(parentMap[node]);
                }
            }
            k--;
        }
        return result;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left) {
            parentMap[root->left] = root;
            dfs(root->left);
        }

        if (root->right) {
            parentMap[root->right] = root;
            dfs(root->right);
        }
    }
private:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    unordered_set<TreeNode*> visited;
};