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
    ListNode* rotateRight(ListNode* head, int k) {
        // traverse list, check total list count
        // first, k = k % total list count
        // second, go k, and concat k~ to the front
        // return
        // TC: O(n)
        // SC: O(1)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* cur = head;
        ListNode* tail = nullptr;
        int total = 0;
        while (cur) {
            tail = cur;
            cur = cur->next;
            total++;
        }

        //first
        k = k % total;
        if (k == 0) {
            return head;
        }

        //second
        ListNode dummy(0);
        dummy.next = head;
        cur = &dummy;

        int move = total - k;
        while (move > 0) {
            cur = cur->next;
            move--;
        }
        dummy.next = cur->next;
        cur->next = nullptr;
        tail->next = head;
        return dummy.next;
    }
};