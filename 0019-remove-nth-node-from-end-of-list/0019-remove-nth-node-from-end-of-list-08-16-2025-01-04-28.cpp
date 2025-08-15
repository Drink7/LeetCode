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
        // prev node, with a fast pointer
        // TC: O(n)
        // SC: O(1)
        ListNode dummy(0);
        ListNode* prev = &dummy;
        prev->next = head;

        // Go k steps
        while (n > 0 && head) {
            head = head->next;
            n--;
        }

        // Start go
        while (head) {
            head = head->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return dummy.next;
    }
};