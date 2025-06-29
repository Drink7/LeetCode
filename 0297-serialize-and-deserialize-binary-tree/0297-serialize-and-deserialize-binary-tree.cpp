/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // TC: O(n)
        // SC: O(1)
        if (root == nullptr) {
            return "N";
        }
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodeList;
        stringstream ss(data);
        string tmp;
        while (ss >> tmp) {
            nodeList.push_back(tmp);
        }
        return deserializeHelper(nodeList);
    }

    TreeNode* deserializeHelper(vector<string>& nodeList) {
        if (nodeList[index] == "N") {
            index++;
            return nullptr;
        }
        int val = stoi(nodeList[index]);
        index++;
        TreeNode* node = new TreeNode(val);
        node->left = deserializeHelper(nodeList);
        node->right = deserializeHelper(nodeList);
        return node;
    }
private:
    int index = 0;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));