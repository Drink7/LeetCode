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
        // fast slow pointer
        // TC: O(n)
        // SC: O(1)
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // go n steps first
        while (n > 0 && fast != nullptr) {
            fast = fast->next;
            n--;
        }

        // go with slow
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    
        if (slow->next) {
            slow->next = slow->next->next;
        }
        
        return dummy->next;;
    }
};