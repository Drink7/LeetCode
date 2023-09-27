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
        // preorder -> subtree first element must be the subtree root
        // inorder, we could find the subtree root position, its left is its left subtree, its right is its right subtree
        // TC: O(n)
        // SC: O(1)
        return buildHelper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        int inorderRootId = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (rootVal == inorder[i]) {
                inorderRootId = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(rootVal);
        int leftSubSize = inorderRootId - inStart;
        int rightSubSize = inEnd - inorderRootId;
        root->left =  buildHelper(preorder, inorder, preStart + 1, inStart, inStart + leftSubSize - 1);
        root->right = buildHelper(preorder, inorder, preStart + leftSubSize + 1, inorderRootId + 1, inEnd);
        return root;
    }
};