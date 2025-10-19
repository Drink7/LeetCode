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
    ListNode* deleteDuplicates(ListNode* head) {
        // head node might be gone -> use dummy node
        // dummy->next = head;
        // compare cur->next & cur->next->next each round
        ListNode dummy(-100000);
        ListNode* cur = &dummy;
        cur->next = head;
        while (cur->next && cur->next->next) {
            int val = cur->next->val;
            if (val == cur->next->next->val) {
                while (cur->next && val == cur->next->val) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};