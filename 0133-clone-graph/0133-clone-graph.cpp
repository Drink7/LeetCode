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
        // DFS, go through whole graph
        // TC: O(n)
        // SC: O(n)
        if (node == nullptr) {
            return node;
        }

        if (cloneDict.count(node->val)) {
            return cloneDict[node->val];
        }

        Node* cloneNode = new Node(node->val);
        cloneDict[node->val] = cloneNode;
        for (auto const& neighbor : node->neighbors) {
            Node* cloneNeighbor = cloneGraph(neighbor);
            cloneNode->neighbors.push_back(cloneNeighbor);
        }
        return cloneNode;
    }
private:
    unordered_map<int, Node*> cloneDict;
};