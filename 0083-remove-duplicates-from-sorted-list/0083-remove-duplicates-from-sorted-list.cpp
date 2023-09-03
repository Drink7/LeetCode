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
        // if next node is equal to the base node, keep go to the next node until the node value is not the same as base node
        // TC: O(n)
        // SC: O(1)
        if (head == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;
        while (head != nullptr) {
            ListNode* next = head->next;
            while (next!= nullptr && next->val == head->val) {
                next = next->next;
            }

            head->next = next;
            head = head->next;
        }
        return dummy->next;
    }
};