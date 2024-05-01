/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        // preorder traversal
        // TC: O(n)
        // SC: O(n)
        vector<int> result;
        preorderHelper(result, root);
        return result;
    }

    void preorderHelper(vector<int>& result, Node* root) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        for (auto const& node : root->children) {
            preorderHelper(result, node);
        }
    }
};