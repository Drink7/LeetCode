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
        // recursive, if list1 & list2 both null, return
        // if list1 or list2 null, return the non null
        // else, concate
        // TC: O(n)
        // SC: O(n)
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        if (list1 && list2) {
            if (list1->val > list2->val) {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            } else {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
        } else {
            if (list1 == nullptr) {
            return list2;
            } else {
                return list1;
            }
        }
        */
        // iterative, dummy node
        // start from a dummy node
        // if list1->val > list2->val
        // dummy->next = list2
        // list2 = list2->next
        // TC: O(m + n)
        // SC: O(1)
        ListNode* dummy = new ListNode(0);
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
        } else {
            cur->next = list2;
        }

        return dummy->next;
    }
};