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
        // preorder to concat string
        if (root == nullptr) {
            return "N";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // preorder to construct tree
        stringstream ss(data);
        // Would get TLE when using a vector to tokenize and store all nodes but kept getting TLE 
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        cout << "token.size(): " << tokens.size() << endl;
        return deserializeHelper(tokens);
    }

    TreeNode* deserializeHelper(vector<string>& data) {
        // preorder to construct tree
        if (data[index] == "N") {
            return nullptr;
        }

        int val = stoi(data[index]);
        TreeNode* node = new TreeNode(val);
        index++;
        node->left = deserializeHelper(data);
        index++;
        node->right = deserializeHelper(data);
        cout << index << endl;
        return node;
    }
private:
    int index = 0;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));