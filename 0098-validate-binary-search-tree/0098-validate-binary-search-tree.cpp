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
    bool isValidBST(TreeNode* root) {
        /*
        // store in vector then compare
        // TC: O(n)
        // SC: O(n)
        vector<int> nodes;
        validBSTHelper(root, nodes);

        for (int i = 1; i < nodes.size(); i++) {
            if (nodes[i - 1] >= nodes[i]) {
                return false;
            }
        }
        return true;
        */
        // one-pass with no extra space
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr) {
            return true;
        }

        if (isValidBST(root->left)) {
            if (prev && prev->val >= root->val) {
                return false;
            }
            prev = root;
            return isValidBST(root->right);
        } else {
            return false;
        }
    }

    /*
    void validBSTHelper(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) {
            return;
        }
        validBSTHelper(root->left, nodes);
        nodes.push_back(root->val);
        validBSTHelper(root->right, nodes);
    }
    */
private:
    TreeNode* prev = nullptr;
    bool isValid = true;
};