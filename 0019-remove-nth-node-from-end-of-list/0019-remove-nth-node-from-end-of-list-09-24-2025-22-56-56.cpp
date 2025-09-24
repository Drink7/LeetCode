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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // fast go n + 1 steps
        // if fast  == null
        // slow->next = slow->next->next
        // return cur->next
        // TC: O(n)
        // SC: O(1)
        ListNode dummy(0);
        ListNode* cur = &dummy;
        cur->next = head;
        ListNode* slow = cur;
        ListNode* fast = cur;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};