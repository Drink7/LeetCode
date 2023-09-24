/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // method 1: store all nodes and reorder
        // TC: O(n)
        // SC: O(n)
        vector<ListNode*> nodeList;
        ListNode* cur = head;
        while (cur != nullptr) {
            nodeList.push_back(cur);
            cur = cur->next;
        }

        // start to concat
        int left = 0;
        int right = nodeList.size() - 1;
        while (left < right) {
            nodeList[left]->next = nodeList[right];
            left++;
            if (left < right) {
                nodeList[right]->next = nodeList[left];
                right--;
            }
        }
        nodeList[left]->next = nullptr;

        /*
        // method fast slow pointer
        // TC: O(n)
        // SC: O(1)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse right
        ListNode* leftPart = head;
        ListNode* rightPart = reverseList(slow);

        // concat left & right
        while (leftPart != nullptr && rightPart != nullptr) {
            ListNode* next = leftPart->next;
            leftPart->next = rightPart;
            leftPart = next;

            next = rightPart->next;
            rightPart->next = leftPart;
            rightPart = next;
        }

        if (leftPart) {
            leftPart->next = nullptr;
        }

        // no need to handle rightPart since the leftPart sizr would always >= rightPart
    }

    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        while (node != nullptr) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
        */
    }
};