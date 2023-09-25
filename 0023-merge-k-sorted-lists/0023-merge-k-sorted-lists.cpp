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
        // TC: O(nlogn)
        // SC: O(1)
        return mergeSort(lists, 0, lists.size() - 1);
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int left, int right) {
        if (left > right) {
            return nullptr;
        } else if (left == right) {
            return lists[left];
        } else {
            int mid = left + (right - left) / 2;
            ListNode* leftNode = mergeSort(lists, left, mid);
            ListNode* rightNode = mergeSort(lists, mid + 1, right);
            return merge(leftNode, rightNode);
        }
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (left && right) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }

        if (left) {
            cur->next = left;
        }

        if (right) {
            cur->next = right;
        }

        cur = dummy->next;
        delete(dummy);
        return cur;
    }
};