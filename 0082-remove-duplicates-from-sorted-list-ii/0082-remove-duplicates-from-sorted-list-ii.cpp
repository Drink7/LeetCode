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
        // use prev, cur, next node
        // TC: O(n)
        // SC: O(1)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        dummy->next = head;

        while (head != nullptr) {
            while (head->next != nullptr && head->val == head->next->val) {
                head = head->next;
            }

            if (prev->next == head) {
                prev = prev->next;
            } else {
                prev->next = head->next;
            }
            head = head->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};