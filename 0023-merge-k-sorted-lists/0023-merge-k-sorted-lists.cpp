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
        // two two merge
        // TC: O(m * n), m lists, lists average is n
        // SC: O(1)
        if (lists.size() == 0) {
            return nullptr;
        }

        ListNode* result = lists[0];
        vector<ListNode*> copyList(lists.begin(), lists.end());
        while (copyList.size() > 1) {
            vector<ListNode*> subList;

            for (int i = 0; i < copyList.size(); i = i + 2) {
                if (i + 1 >= copyList.size()) {
                    subList.push_back(mergeList(copyList[i], nullptr));
                } else {
                    subList.push_back(mergeList(copyList[i], copyList[i + 1]));
                }
            }

            // reset copyList
            copyList.clear();
            copyList.assign(subList.begin(), subList.end());
            result = copyList[0];

        }
        return result;
    }

    ListNode* mergeList(ListNode* node1, ListNode* node2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (node1 && node2) {
            if (node1->val < node2->val) {
                cur->next = node1;
                node1 = node1->next;
            } else {
                cur->next = node2;
                node2 = node2->next;
            }
            cur = cur->next;
        }

        if (node1) {
            cur->next = node1;
        }

        if (node2) {
            cur->next = node2;
        }
        return dummy->next;
    }
};