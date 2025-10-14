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
    int goodNodes(TreeNode* root) {
        // Pass current high value to their child nodes
        // pre-order
        // TC: O(n)
        // SC: O(n)
        dfs(root, -100000);
        return cnt;
    }

    void dfs(TreeNode* root, int prevMax) {
        if (root == nullptr) {
            return;
        }
        
        if (root->val >= prevMax){
            cnt++;
        }

        int curMax = max(root->val, prevMax);
        dfs(root->left, curMax);
        dfs(root->right, curMax);
    }
private:
    int cnt = 0;
};