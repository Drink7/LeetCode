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
        /*
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
        */

        // Two Pointer with fast slow pointer
        // TC: O(logn)
        // SC: O(1)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* leftPart = head;
        ListNode* rightPart = reverse(slow);
        while (leftPart != nullptr && rightPart != nullptr) {
            ListNode* next = leftPart->next;
            leftPart->next = rightPart;
            leftPart = next;

            next = rightPart->next;
            rightPart->next = leftPart;
            rightPart = next;
        }

        if (leftPart != nullptr) {
            leftPart->next = nullptr;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};