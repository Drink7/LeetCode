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
    bool isPalindrome(ListNode* head) {
        // two pointer and find the middle point
        // use a dummy node
        // TC: O(n)
        // SC: O(1)
        if (head == nullptr) {
            return true;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            // fast
            fast = fast->next->next;

            // slow
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // start check palindrome
        ListNode* right = slow->next;
        slow->next = prev;

        // odd numbers
        if (fast == nullptr) {
            slow = slow->next;
        }

        while (slow != nullptr && right != nullptr) {
            if (slow->val != right->val) {
                return false;
            }
            slow = slow->next;
            right = right->next;
        }
        return true;
    }
};