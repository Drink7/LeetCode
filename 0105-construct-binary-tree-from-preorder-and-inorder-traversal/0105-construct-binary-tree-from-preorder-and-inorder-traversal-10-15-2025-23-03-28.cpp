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
        // pre-order-> root / left / right
        // in-order-> left / root / right
        // preorder the first must tree root, left part, right part
        // left part size? Check in-order
        // find in-order root, its left part size is equal to pre-order left part size
        // its right part size is equal to pre-order right part size
        // create every root node
        // TC: O(n)
        // SC: O(1)

        // 3, [9, 20,] [15, 7] preorder, pre_order_start
        // [9,] 3, [15, 20, 7] inorder, need inorder_start, inorder_end

        return buildHelper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int rootId = inStart;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootId = i;
                break;
            }
        }

        root->left = buildHelper(preorder, inorder, preStart + 1, inStart, rootId - 1);
        root->right = buildHelper(preorder, inorder, preStart + (rootId - inStart + 1), rootId + 1, inEnd); 
        return root; 
    }
};