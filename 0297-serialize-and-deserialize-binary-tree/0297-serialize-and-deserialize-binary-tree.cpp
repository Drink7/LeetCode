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
        // postorder
        // TC: O(n)
        // SC: O(logh)
        if (root == nullptr) {
            return "N";
        } else {
            return to_string(root->val) + "." + serialize(root->left) + "." + serialize(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token = "";
        vector<string> dataList;
        int start = 0;
        while (getline(ss, token, '.')) {
            dataList.push_back(token);
        }
        return deserializeHelper(dataList, start);
    }

    TreeNode* deserializeHelper(vector<string>& datas, int& start) {
        if (datas[start] == "N") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(datas[start]));
        start++;
        root->left = deserializeHelper(datas, start);
        start++;
        root->right = deserializeHelper(datas, start);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));