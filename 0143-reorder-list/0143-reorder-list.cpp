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
    void reorderList(ListNode* head) {
        // store all node then do interleave
        // TC: O(n)
        // SC: O(1)
        vector<ListNode*> list;
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        dummy->next = cur;
        while (cur != nullptr) {
            list.push_back(cur);
            cur = cur->next;
        }

        // interleave the nodes
        int left = 0;
        int right = list.size() - 1;
        while (left <= right) {
            cur = list[left];
            cur->next = list[right];
            left++;

            // Note the corner case
            if (left <= right) {
                cur = cur->next;
                cur->next = list[left];
                right--;
            }
        }
        cur->next = nullptr;
    }
};