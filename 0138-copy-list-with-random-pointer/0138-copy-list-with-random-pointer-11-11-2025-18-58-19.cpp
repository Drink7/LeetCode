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
        // vector store nodes
        // use next to traverse the linked list
        // then deep copy the list
        // then traverse again, this time is for random index
        // TC: O(n)
        // SC: O(n)
        unordered_map<Node*, Node*> randMap;
        randMap[nullptr] = nullptr;
        Node* cur = head;

        while (cur) {
            Node* copyCur = new Node(cur->val);
            randMap[cur] = copyCur;
            cur = cur->next;
        }

        // concat next and random
        cur = head;
        while (cur) {
            randMap[cur]->next = randMap[cur->next];
            randMap[cur]->random = randMap[cur->random];
            cur = cur->next;
        }

        return randMap[head];
    }
};