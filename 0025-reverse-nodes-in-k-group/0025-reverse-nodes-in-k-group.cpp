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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // cur = head
        // walk k steps
        // prev = head
        // reverse k steps
        // return dummy.next
        // TC: O(n)
        // SC: O(1)
        if (head == nullptr) {
            return head;
        }

        if (k == 1) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr) {
                break;
            }

            // reverse from groupPrev to kth
            ListNode* next = kth->next;
            ListNode* prev = next;
            ListNode* cur = groupPrev->next;
            while (cur != next) {
                ListNode* tmpNext = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmpNext;
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }
        return dummy.next;
    }

    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};