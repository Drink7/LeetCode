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
        /*
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
        */

        // BFS
        // TC: O(n)
        // SC: O(n)
        if (node == nullptr) {
            return node;
        }

        Node* cloned = new Node(node->val);
        cloneDict[cloned->val] = cloned;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                Node* n = q.front();
                q.pop();
                for (auto const& neighbor : n->neighbors) {
                    Node* cloneNeighbor;
                    if (cloneDict.count(neighbor->val)) {
                        cloneNeighbor = cloneDict[neighbor->val];
                    } else {
                        cloneNeighbor = new Node(neighbor->val);
                        cloneDict[cloneNeighbor->val] = cloneNeighbor;
                        q.push(neighbor);
                    }
                    cloneDict[n->val]->neighbors.push_back(cloneNeighbor);
                }
            }
        }
        return cloned;
    }
private:
    unordered_map<int, Node*> cloneDict;
};