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
        // Merge with recursion way
        // TC: O(m + n)
        // SC: O(m + n)
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
        // Merge with iterative way
        // TC: O(m + n)
        // SC: O(1)
        ListNode* dummyNode = new ListNode();
        ListNode* curNode;
        curNode = dummyNode;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                curNode->next = list2;
                list2 = list2->next;
            } else {
                curNode->next = list1;
                list1 = list1->next;
            }
            curNode = curNode->next;
        }

        if (list1 == nullptr) {
            curNode->next = list2;
        }

        if (list2 == nullptr) {
            curNode->next = list1;
        }

        /*
        // delete dummy node for not memory leakage
        curNode = dummyNode->next;
        delete dummyNode;
        return curNode;
        */
        return dummyNode->next;
    }
};