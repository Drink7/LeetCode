/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // hash map
        // TC: O(n)
        // SC: O(n)
        if (node == nullptr) {
            return node;
        }

        int val = node->val;
        if (dict.count(val) > 0) {
            return dict[val];
        }

        Node* newNode = new Node(val);
        dict[val] = newNode;
        for (auto const& neigh : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neigh));
        }
        return newNode;
    }
private:
    unordered_map<int, Node*> dict;
};