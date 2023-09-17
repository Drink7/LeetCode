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
    ListNode* partition(ListNode* head, int x) {
        // two pointer
        // TC: O(n)
        // SC: O(1)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode();
        ListNode* smallHead = dummy;
        ListNode* largeHead = dummy;
        ListNode* smallCur = dummy;
        ListNode* largeCur = dummy;
        while (head != nullptr) {
            if (head->val < x) {
                if (smallHead == dummy) {
                    smallHead->next = head;
                    smallHead = smallHead->next;
                    smallCur = smallHead;
                } else {
                    smallCur->next = head;
                    smallCur = smallCur->next;
                }
            } else {
                if (largeHead == dummy) {
                    largeHead->next = head;
                    largeHead = largeHead->next;
                    largeCur = largeHead;
                } else {
                    largeCur->next = head;
                    largeCur = largeCur->next;
                }
            }
            head = head->next;
        }
        smallCur->next = (largeHead == dummy) ? nullptr : largeHead;
        largeCur->next = nullptr;
        return (smallHead != dummy) ? smallHead : largeHead;
    }
};