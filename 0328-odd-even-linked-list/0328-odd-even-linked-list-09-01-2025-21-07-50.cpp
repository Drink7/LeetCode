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
    ListNode* oddEvenList(ListNode* head) {
        // next->next
        // TC: O(n)
        // SC: O(n)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* A = head;
        ListNode* right = head->next, *B = head->next;

        while (A->next && B->next) {
            A->next = A->next->next;
            B->next = B->next->next;

            if (A->next) {
                A = A->next;
            }

            if (B->next) {
                B = B->next;
            }
        }

        A->next = right;
        return head;
    }
};