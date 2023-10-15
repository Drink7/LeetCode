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
        // TC: O(nlogn)
        // SC: O(n)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // find mid
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
        return mergeList(left, right);
    }

    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (left && right) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }

        if (left) {
            cur->next = left;
        }

        if (right) {
            cur->next = right;
        }
        cur = dummy->next;
        delete(dummy);
        return cur;
    }
};