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
        // trhee node
        // fast node go n nodes first
        // slow node go with the same speed until fast node == nullptr
        // keep tracking the prev node of slow
        // TC: O(n)
        // SC: O(1)
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && n > 0) {
            fast = fast->next;
            n--;
        }

        if (fast != nullptr) {
            while (fast != nullptr) {
                fast = fast->next;
                prev = slow;
                slow = slow->next;
            }
            prev->next = slow->next;
            return head;
        } else {
            // if n == total node size
            // we would remove the head node
            return head->next;
        }
    }
};