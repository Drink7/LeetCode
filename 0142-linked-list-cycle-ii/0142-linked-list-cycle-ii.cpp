/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Two pointer with fast & slow
        // Tortoise and Hare Algorithm and find the cycle start node
        // move one pointer node back to head and keep those two pointer go with the same speed
        // TC: O(n)
        // SC: O(1)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                // move fast back to head node and move with the same speed of slow
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        // there is no cycle
        return nullptr;
    }
};