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
        // Rebuild tree
        // preorder:
        // first must be root
        // root next must be left subtree root
        // Use the root to find the left subtree size in inorder
        // inorder left size is left subtree size
        // inorder right size is right subtree size
        // preorder right subtree root = root + left size + 1 to the end
        // TC: O(n)
        return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int pivot = inStart;
        for (int i = inStart; i <= inEnd; i++) {
            if (preorder[preStart] == inorder[i])
            {
                pivot = i;
                break;
            }
        }

        int leftSubTreeSize = pivot - inStart;
        int rightSubTreeSize = inEnd - pivot;
        root->left = buildTreeHelper(preorder, inorder, preStart + 1, inStart, pivot - 1);
        root->right = buildTreeHelper(preorder, inorder, preStart + leftSubTreeSize + 1, pivot + 1, inEnd);
        return root;
    }
};