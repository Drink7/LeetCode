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
        // dummy node skills
        // TC: O(n)
        // SC: O(1)
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (head != nullptr) {
            while (head != nullptr && head->val == val) {
                head = head->next;
            }
            cur->next = head;
            cur = head;
            if (head != nullptr) {
                head = head->next;
            }
        }
        return dummy->next;
    }
};