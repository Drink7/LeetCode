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
    ListNode* removeElements(ListNode* head, int val) {
        // use dummy node
        // keep removing linked list node
        // while (cur && cur->next)
        // if cur->next == val
        // cur->next = cur->next->next
        // TC: O(n)
        // SC: O(1)
        // iterative
        ListNode dummy(0);
        ListNode* cur = &dummy;
        cur->next = head;
        while (cur && cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};