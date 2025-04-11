/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // use unorderd_map<Node*, Node*> to store old Node* and new Node*
        // traverse linked list from head to set random and next
        // TC: O(n)
        // SC: O(n)
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[nullptr] = nullptr;

        Node* cur = head;
        while (cur != nullptr) {
            Node* newNode = new Node(cur->val);
            nodeMap[cur] = newNode;
            cur = cur->next;
        }

        // store random value and next
        cur = head;
        while (cur != nullptr) {
            nodeMap[cur]->next = nodeMap[cur->next];
            nodeMap[cur]->random = nodeMap[cur->random];
            cur = cur->next;
        }
        return nodeMap[head];
    }
};