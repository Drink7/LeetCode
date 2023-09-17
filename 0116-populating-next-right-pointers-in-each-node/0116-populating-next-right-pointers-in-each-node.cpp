/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /*
        // BFS + queue
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr) {
            return root;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                Node* node = q.front();
                q.pop();

                if (i + 1 < qSize) {
                    node->next = q.front();
                } else {
                    node->next = nullptr;
                }

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return root;
        */

        /*
        // constant space iterative
        // TC: O(n)
        // SC: O(1)
        Node* leftMost = root;
        while (leftMost != nullptr) {
            Node* cur = leftMost;
            while (cur != nullptr) {
                if (cur->left != nullptr) {
                    cur->left->next = cur->right;
                }

                if (cur->right != nullptr && cur->next != nullptr) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            leftMost = leftMost->left;
        }
        return root;
        */

        // constant space recursive
        // TC: O(n)
        // SC: O(1)
        if (root == nullptr) {
            return root;
        }
        connectHelper(root->left, root->right);
        return root;
    }

    void connectHelper(Node* left, Node* right) {
        if (left == nullptr && right == nullptr) {
            return;
        }

        left->next = right;
        connectHelper(left->left, left->right);
        connectHelper(left->right, right->left);
        connectHelper(right->left, right->right);
    }
};