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
    void flatten(TreeNode* root) {
        /*
        // preorder traversal
        // use a vector to store
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr) {
            return;
        }

        flattenHelper(root);

        // flatten to linkedlist
        for (int i = 0; i < nodeList.size() - 1; i++) {
            nodeList[i]->left = nullptr;
            nodeList[i]->right = nodeList[i + 1];
        }
        nodeList.back()->left = nullptr;
        nodeList.back()->right = nullptr;
        */

        // postorder
        // TC: O(n)
        // SC: O(1)
        if (root == nullptr) {
            return;
        }
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;

        flatten(root->left);
        flatten(root->right);

        root->left = nullptr;
        root->right = leftNode;

        while (root->right != nullptr) {
            root = root->right;
        }
        root->right = rightNode;
    }

    void flattenHelper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        nodeList.push_back(node);
        flattenHelper(node->left);
        flattenHelper(node->right);
    }

private:
    vector<TreeNode*> nodeList;
};