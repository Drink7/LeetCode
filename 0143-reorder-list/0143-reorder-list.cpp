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
        while (head != nullptr) {
            list.push_back(head);
            head = head->next;
        }

        // interleave the nodes
        int left = 0;
        int right = list.size() - 1;
        while (left < right) {
            list[left]->next = list[right];
            left++;

            // Note the corner case
            if (left < right) {
                list[right]->next = list[left];
                right--;
            }
        }
        list[right]->next = nullptr;
    }
};