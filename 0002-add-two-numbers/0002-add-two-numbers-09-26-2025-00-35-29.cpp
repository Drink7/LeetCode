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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // dummy node + l1 && l2
        // sum and carry
        // if carry exist, new a node and concat
        // TC: O(n), n is the longest size
        // SC: O(1)
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int sum = 0;
        int carry = 0;
        while (l1 || l2 || carry) {
            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            sum = carry + l1Val + l2Val;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);

            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};