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
        // find mid & reverse list
        // TC: O(n)
        // SC: O(1
        // find mid -> slow/fast
        // slow->next will be the left part first
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* left = slow->next;
        slow->next = nullptr;
        left = reverseList(left);

        // reorder
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (head && left) {
            cur->next = head;
            cur = cur->next;
            head = head->next;

            cur->next = left;
            cur = cur->next;
            left = left->next;
        }

        if (head) {
            cur->next = head;
        }
        head = dummy->next;
    }

    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        while (node) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};