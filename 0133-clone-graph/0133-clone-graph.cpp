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
        // no repeated edges and self loop
        // no repeated value node
        // all nodes can be visited starting from given node
        // TC: O(m * n), m nodes with n edges
        // SC: O(m * n)
        if (node == nullptr) {
            return nullptr;
        }
        
        int val = node->val;
        if (adjList.count(val) < 1) {
            Node* newNode = new Node(node->val);
            adjList[val] = newNode;
            
            int listSize = node->neighbors.size();
            for (int i = 0; i < listSize; i++) {
                Node* newNeighbor = cloneGraph(node->neighbors[i]);
                newNode->neighbors.push_back(newNeighbor);
            }
            return newNode;
        } else {
            return adjList[val];
        }
    }
private:
    unordered_map<int, Node*> adjList;
};