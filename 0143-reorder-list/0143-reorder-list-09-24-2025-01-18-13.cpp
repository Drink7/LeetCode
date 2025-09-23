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
        // fast slow find mid part
        // use a dummy node
        // reverse right part
        // reorder concat
        // TC; O(n)
        // SC: O(1)
        ListNode dummy(0);
        ListNode* cur = &dummy;
        cur->next = head;
        ListNode* slow = cur;
        ListNode* fast = cur;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = nullptr;

        right = reverse(right);

        while (left && right) {
            ListNode* next = left->next;
            left->next = right;
            left = next;

            next = right->next;
            right->next = left;
            right = next;
        }
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};