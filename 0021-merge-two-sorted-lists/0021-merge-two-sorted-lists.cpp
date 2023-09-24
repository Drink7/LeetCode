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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
        // Iterative
        // TC: O(m + n)
        // SC: O(1)
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        if (list1) {
            cur->next = list1;
        }

        if (list2) {
            cur->next = list2;
        }

        cur = dummy->next;
        delete(dummy);
        return cur;
        */

        // Recursive
        // TC: O(m + n)
        // SC: O(m + n)
        if (list1 && list2) {
            if (list1->val > list2->val) {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            } else {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
        } else if (list1) {
            return list1;
        } else {
            return list2;
        }
    }
};