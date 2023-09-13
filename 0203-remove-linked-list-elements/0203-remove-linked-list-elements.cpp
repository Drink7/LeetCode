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
    ListNode* removeElements(ListNode* head, int val) {
        // dummy node skills
        // TC: O(n)
        // SC: O(1)
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        dummy->next = head;
        while (head != nullptr) {
            if (head->val == val) {
                prev->next = head->next;
                delete head;
                head = prev->next;
            } else {
                prev = head;
                head = head->next;
            }
        }
        // remove memory leak
        head = dummy->next;
        delete dummy;
        return head;
    }
};