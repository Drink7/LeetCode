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
        if (head == nullptr) {
            return head;
        }

        unordered_map<Node*, Node*> randMap;
        Node* cur = head;

        while (cur) {
            Node* copyCur = new Node(cur->val);
            randMap[cur] = copyCur;
            cur = cur->next;
        }

        // concat next and random
        cur = head;
        while (cur) {
            if (cur->next) {
                randMap[cur]->next = randMap[cur->next];
            }
            
            if (cur->random) {
                randMap[cur]->random = randMap[cur->random];
            }
            cur = cur->next;
        }

        return randMap[head];
    }
};