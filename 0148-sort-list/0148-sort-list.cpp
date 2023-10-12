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
    ListNode* sortList(ListNode* head) {
        // merge sort
        // TC: O(nlogn)
        // SC: O(1)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return mergeTwoList(left, right);
    }

    ListNode* mergeTwoList(ListNode* left, ListNode* right) {
        if (left == nullptr) {
            return right;
        }

        if (right == nullptr) {
            return left;
        }

        if (left->val > right->val) {
            right->next = mergeTwoList(left, right->next);
            return right;
        } else {
            left->next = mergeTwoList(left->next, right);
            return left;
        }
    }
};