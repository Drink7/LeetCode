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
        // fast slow pointer
        // TC: O(n)
        // SC: O(1)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* leftPart = head;
        ListNode* rightPart = reverseList(slow);
        while (leftPart && rightPart) {
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
    }
};