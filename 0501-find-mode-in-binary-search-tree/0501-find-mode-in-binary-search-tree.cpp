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
    vector<int> findMode(TreeNode* root) {
        // Brute force in-order traversal
        // use map
        // TC: O(n)
        // SC: O(n)
        modeHelper(root);
        vector<int> result;
        for (auto const& p : modeMap) {
            if (p.second == maxCnt) {
                result.push_back(p.first);
            }
        }
        return result;
    }

    void modeHelper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        modeHelper(root->left);
        modeMap[root->val]++;
        maxCnt = max(maxCnt, modeMap[root->val]);
        modeHelper(root->right);
    }

private:
    int maxCnt = -1;
    int preVal = -200000;
    unordered_map<int, int> modeMap;
};