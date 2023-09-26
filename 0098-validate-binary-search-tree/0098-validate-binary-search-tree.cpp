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
        // BST -> inorder
        // TC: O(n)
        // SC: O(n)
        traverseBST(root);

        for (int i = 0; i < bstList.size() - 1; i++) {
            if (bstList[i] >= bstList[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void traverseBST(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        traverseBST(root->left);
        bstList.push_back(root->val);
        traverseBST(root->right);
    }
private:
    vector<int> bstList;
};