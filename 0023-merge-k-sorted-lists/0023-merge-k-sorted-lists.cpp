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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
        // merge two list enhanced
        // TC: O(nk), n is lists number, k is average list count
        // SC: O(nk)
        if (lists.size() == 0) {
            return nullptr;
        }

        int n = lists.size();
        for (int i = 1; i < n; i++) {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
        */

        // Divide and conquer and merge
        // TC: O(nk)
        // SC: O(1)
        if (lists.size() == 0) {
            return nullptr;
        }

        int n = lists.size();
        while (n > 1) {
            int group = (n + 1) / 2;
            for (int i = 0; i < group; i++) {
                lists[i] = mergeTwoLists(lists[i * 2], (i * 2 + 1) < n ? lists[(i * 2) + 1] : nullptr);
            }
            n = group;
        }
        return lists[0];
    }
    /*
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // merge two list, recursive
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
    }
    */

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // merge two list, iterative
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
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

        if (list1 == nullptr) {
            cur->next = list2;
        }

        if (list2 == nullptr) {
            cur->next = list1;
        }

        return dummy->next;
    }
};