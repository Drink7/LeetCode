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
        // DFS, build copy node map
        // TC: O(n)
        // SC: O(n)
        if (node == nullptr) {
            return node;
        }

        int val = node->val;
        if (newNodeMap.count(val) < 1) {
            // not exist, create new one
            Node* newNode = new Node(val);
            newNodeMap[val] = newNode;
            for (auto const& neighbor : node->neighbors) {
                Node* newNeighbor = cloneGraph(neighbor);
                if (newNeighbor) {
                    newNodeMap[val]->neighbors.push_back(newNeighbor);
                }
            }
        }
        return newNodeMap[val];
    }
private:
    unordered_map<int, Node*> newNodeMap;
};