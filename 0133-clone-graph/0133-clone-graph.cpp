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
        // use BFS to clone node
        // visited map means cloned or not (since node value is unique)
        // TC: O(n)
        // SC: O(n)
        if (node == nullptr) {
            return nullptr;
        }

        // traverse node
        Node* clone = new Node(node->val);
        clonedMap[node->val] = clone;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                Node* n = q.front();
                q.pop();

                for (int j = 0; j < n->neighbors.size(); j++) {
                    Node* neighbor = n->neighbors[j];
                    if (!clonedMap.count(neighbor->val)) {
                        Node* cloneNeighbor = new Node(neighbor->val);
                        clonedMap[neighbor->val] = cloneNeighbor;
                        clonedMap[n->val]->neighbors.push_back(clonedMap[neighbor->val]);
                        q.push(neighbor);
                    } else {
                        clonedMap[n->val]->neighbors.push_back(clonedMap[neighbor->val]);
                    }
                }
            }
        }
        
        return clonedMap[node->val];
    }
private:
    unordered_map<int, Node*> clonedMap;
};