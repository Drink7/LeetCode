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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->next == nullptr) {
            return head;
        }

        ListNode* prev = swapPairs(head->next->next);

        // start reverse pairs
        int cnt = 2;
        while (cnt > 0) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            cnt--;
        }
        return prev;
    }
};