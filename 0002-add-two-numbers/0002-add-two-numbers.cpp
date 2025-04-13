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
        // TC: O(m + n)
        // SC: O(1)
        // make final l1 is the sum of l1 + l2
        ListNode* prev = nullptr;
        ListNode* head = l1;
        int carry = 0;
        while (l1 && l2) {
            int val = carry + l1->val + l2->val;
            l1->val = val % 10;
            carry = val / 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        // check l1 or l2
        while (l1) {
            int val = carry + l1->val;
            l1->val = val % 10;
            carry = val / 10;
            prev = l1;
            l1 = l1->next;
        }

        while (l2) {
            int val = carry + l2->val;
            l2->val = val % 10;
            carry = val / 10;
            prev->next = l2;
            prev = prev->next;
            l2 = l2->next;
        }
        
        // both l1 & l2 is nullptr, check carry
        if (carry != 0) {
            ListNode* last = new ListNode(carry);
            prev->next = last;
        }
        return head;
    }
};