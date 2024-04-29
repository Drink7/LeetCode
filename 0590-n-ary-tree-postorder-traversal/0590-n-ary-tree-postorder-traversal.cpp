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
    vector<int> postorder(Node* root) {
        // TC: O(n)
        // SC: O(n)
        vector<int> result;
        postorderHelper(result, root);
        return result;
    }

    void postorderHelper(vector<int>& result, Node* root) {
        if (root == nullptr) {
            return;
        }
        vector<Node*> children = root->children;
        for (auto const& child : children) {
            postorderHelper(result, child);
        }
        result.push_back(root->val);
    }
};