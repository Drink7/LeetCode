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
    int findSecondMinimumValue(TreeNode* root) {
        // TC: O(nlogn)
        // SC: O(n)
        unordered_set<int> nodeSet;
        valueHelper(root, nodeSet);
        vector<int> valueArr(nodeSet.begin(), nodeSet.end());
        sort(valueArr.begin(), valueArr.end());
        return valueArr.size() == 1 ? -1 : valueArr[1];
    }

    void valueHelper(TreeNode* root, unordered_set<int>& nodeSet) {
        if (root == nullptr) {
            return;
        }

        nodeSet.insert(root->val);
        valueHelper(root->left, nodeSet);
        valueHelper(root->right, nodeSet);
    }
};