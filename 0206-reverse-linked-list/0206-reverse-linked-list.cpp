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
    ListNode* reverseList(ListNode* head) {
        /*
        // Iterative
        // TC: O(n)
        // SC: O(1)
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
        */
        // Recursive
        // TC: O(n)
        // SC: O(n)
        //return reverseHelper(nullptr, head);

        // Recursive II
        // TC: O(n)
        // SC: O(n)
        if (head == nullptr || head->next == nullptr) {
                return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* reverseHelper(ListNode* prev, ListNode* head) {
        if (head == nullptr) {
            return prev;
        }

        ListNode* next = head->next;
        head->next = prev;
        return reverseHelper(head, next);
    }
};