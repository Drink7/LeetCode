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
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal to list all nodes
        // check the k-th element
        // TC: O(n)
        // SC: O(n)
        traverseBST(root);
        return bstList[k - 1];
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