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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // use dummyNode
        // TC: O(n)
        // SC: O(1)
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curNode = dummy;
        ListNode* prevNode = nullptr;
        for (int i = 0; i < left; i++) {
            prevNode = curNode;
            curNode = curNode->next;
        }

        ListNode* reversePrev = prevNode;
        ListNode* reverseCur = curNode;
        for (int i = left; i <= right; i++) {
            ListNode* next = reverseCur->next;
            reverseCur->next = reversePrev;
            reversePrev = reverseCur;
            reverseCur = next;
        }

        // connect
        prevNode->next = reversePrev;
        curNode->next = reverseCur;
        head = dummy->next;
        delete(dummy);
        return head;
    }
};