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
    bool isSymmetric(TreeNode* root) {
        // iteratively
        // bfs + queue
        // TC: O(n)
        // SC: O(n)
        queue<TreeNode*> q;
        if (root == nullptr) {
            return true;
        }
        q.push(root);
        while (q.size() > 0) {
            int qSize = q.size();
            vector<int> nodeArr;
            for (int i = 0; i < qSize; i++) {
                auto node = q.front();
                q.pop();

                if (node) {
                    nodeArr.push_back(node->val);
                    if (node->left) {
                        q.push(node->left);
                    } else {
                        q.push(nullptr);
                    }
                    if (node->right) {
                        q.push(node->right);
                    } else {
                        q.push(nullptr);
                    }
                } else {
                    nodeArr.push_back(-200); // as nullptr
                }
            }
            // compare like palindrome
            int left = 0;
            int right = nodeArr.size() - 1;
            while (left <= right) {
                cout << "nodeArr[left]: " << nodeArr[left] << ", nodeArr[right]" << nodeArr[right] << endl;
                if (nodeArr[left] != nodeArr[right]) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};