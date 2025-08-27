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
    void reorderList(ListNode* head) {
        // find left & right half (fast slow pointer)
        // reverse right half
        // traverse left & right and concar
        // TC: O(n)
        // SC: O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is the mid point
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* right = reverseList(mid);
        ListNode* left = head;
        ListNode* dummy = new ListNode();
        while (left && right) {
            dummy->next = left;
            left = left->next;
            dummy = dummy->next;

            dummy->next = right;
            right = right->next;
            dummy = dummy->next;
        }

        if (left) {
            dummy->next = left;
        }
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};