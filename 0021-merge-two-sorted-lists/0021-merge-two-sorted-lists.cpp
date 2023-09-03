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
        // recursion
        // TC: O(n * m), n & m is list1 & list2 array size
        // SC: O(1)
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val > list2->val) {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        } else {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        */
        // Iterative
        // dummy node
        // TC: O(n * m), n & m is list1 & list2 array size
        // SC: O(1)
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        if (list1 != nullptr) {
            cur->next = list1;
        }

        if (list2 != nullptr) {
            cur->next = list2;
        }

        return dummy->next;
    }
};