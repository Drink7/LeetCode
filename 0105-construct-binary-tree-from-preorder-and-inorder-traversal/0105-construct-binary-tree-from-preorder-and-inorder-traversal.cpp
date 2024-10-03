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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // TC: O(n)
        // SC: O(n)
        return buildHelper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int preorderStart, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd) {
            return nullptr;
        }

        int rootVal = preorder[preorderStart];
        int rootPos = inorderStart;
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (inorder[i] == rootVal) {
                rootPos = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(rootVal);
        node->left = buildHelper(preorder, inorder, preorderStart + 1, inorderStart, rootPos - 1);
        node->right = buildHelper(preorder, inorder, preorderStart + (rootPos - inorderStart) + 1, rootPos + 1, inorderEnd);
        return node;
    }
};